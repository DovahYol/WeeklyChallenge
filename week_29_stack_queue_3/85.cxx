#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int ans = 0;
        int N = matrix.size();
        if (N < 1)
            return 0;
        int M = matrix[0].size();
        if (M < 1)
            return 0;
        vector<vector<int>> height(N, vector<int>(M));
        for (int j = 0; j < M; j++)
            height[0][j] = matrix[0][j] == '0' ? 0 : 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                height[i][j] = matrix[i][j] == '0' ? 0 : (height[i - 1][j] + 1);
            }
        }
        vector<int> left(M), right(M);
        stack<int> stk;
        for (int i = 0; i < N; i++) {
            fill(left.begin(), left.end(), -1);
            fill(right.begin(), right.end(), M);
            while (!stk.empty())
                stk.pop();
            stk.push(0);
            for (int j = 1; j < M; j++) {
                while (!stk.empty()) {
                    if (height[i][j] > height[i][stk.top()]) {
                        left[j] = stk.top();
                        break;
                    } else {
                        right[stk.top()] = j;
                        stk.pop();
                    }
                }
                stk.push(j);
            }

            for (int j = 0; j < M; j++) {
                ans = max(ans, height[i][j] * (right[j] - left[j] - 1));
            }
        }

        return ans;
    }
};

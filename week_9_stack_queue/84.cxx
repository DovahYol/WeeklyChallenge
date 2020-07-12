#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int N = heights.size();
        vector<int> right(N, N), left(N, -1);
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            while(!stk.empty()) {
                if(heights[i] > heights[stk.top()]) {
                    left[i] = stk.top();
                    break;
                }else{
                    right[stk.top()] = i;
                    stk.pop();
                }
            }
            stk.push(i);
        }

        for (int i = 0; i < N; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        
        return ans;
    }
};

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    struct Queen {
        int x;
        int y;
        Queen(int p_x, int p_y)
            : x(p_x)
            , y(p_y)
        {
        }

        bool operator==(const Queen& another) const
        {
            return x == another.x || y == another.y || (x - another.x == y - another.y) || (x - another.x == another.y - y);
        }
    };
    vector<Queen> stk;
    vector<vector<string>> ans;
    int N;
    vector<vector<string>> solveNQueens(int n)
    {
        N = n;
        bt(0);
        return ans;
    }

    void bt(int m)
    {
        if (m == N) {
            vector<string> temp(N, string(N, '.'));
            for (int i = 0; i < N; i++) {
                temp[i][stk[i].y] = 'Q';
            }
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < N; i++) {
            Queen q(m, i);
            if (find(stk.begin(), stk.end(), q) != stk.end()) {
                continue;
            }
            stk.push_back(q);
            bt(m + 1);
            stk.erase(stk.end() - 1);
        }
    }
};

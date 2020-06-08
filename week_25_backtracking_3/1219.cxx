#include <vector>
using namespace std;

class Solution {
public:
    int x[4] = { -1, 0, 1, 0 };
    int y[4] = { 0, 1, 0, -1 };
    int i, j, m, n;
    vector<vector<int>> m_grid;
    int acc = 0, ans = -1;

    int getMaximumGold(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        m_grid = grid;
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                if (m_grid[a][b] != 0) {
                    i = a;
                    j = b;
                    int temp = m_grid[i][j];
                    acc = temp;
                    m_grid[i][j] = 0;
                    bt();
                    m_grid[i][j] = temp;
                }
            }
        }
        return ans;
    }

    void bt()
    {
        bool stuck = true;
        for (int k = 0; k < 4; k++) {
            i += x[k];
            j += y[k];
            if (invalid(i, j)) {
                i -= x[k];
                j -= y[k];
                continue;
            }
            stuck = false;
            int temp = m_grid[i][j];
            acc += temp;
            m_grid[i][j] = 0;
            bt();
            m_grid[i][j] = temp;
            i -= x[k];
            j -= y[k];
            acc -= temp;
        }

        if (stuck) {
            ans = max(ans, acc);
        }
    }

    bool invalid(int x, int y)
    {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return true;
        }

        return m_grid[x][y] == 0;
    }
};

#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = grid[i][j];
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dist[i][j] += min(dist[i - 1][j], dist[i][j - 1]);
                } else if (i - 1 >= 0) {
                    dist[i][j] += dist[i - 1][j];
                } else if (j - 1 >= 0) {
                    dist[i][j] += dist[i][j - 1];
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};

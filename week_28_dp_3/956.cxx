#include <vector>

using namespace std;

class Solution {
private:
    int maxheight;

public:
    int tallestBillboard(vector<int>& rods)
    {
        if (rods.size() < 2) {
            return 0;
        }
        int sum = 0;
        for (auto& i : rods) {
            sum += i;
        }
        maxheight = 0;
        sort(rods.begin(), rods.end(), greater<int>());
        dfs(rods, 0, rods[0], 0, sum - rods[0]);
        dfs(rods, 0, 0, 0, sum - rods[0]);
        return maxheight;
    }

    void dfs(vector<int>& rods, int index, int left, int right, int remain)
    {
        if (abs(left - right) > remain || left + right + remain <= maxheight * 2) {
            return;
        }
        if (left == right) {
            maxheight = max(maxheight, left);
        }
        index++;
        if (index == rods.size()) {
            return;
        }
        remain -= rods[index];
        dfs(rods, index, left + rods[index], right, remain);
        dfs(rods, index, left, right + rods[index], remain);
        dfs(rods, index, left, right, remain);
    }
};

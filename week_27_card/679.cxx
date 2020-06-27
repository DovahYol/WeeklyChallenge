#include <vector>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums)
    {
        vector<double> temp(nums.begin(), nums.end());
        return bt(temp);
    }

    bool bt(vector<double>& nums)
    {
        if (nums.size() == 1) {
            if (abs(nums[0] - 24) < 1e-6) {
                return true;
            }
            return false;
        }
        vector<double> temp, ops;
        temp.reserve(nums.size() - 1);
        ops.reserve(6);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                double o1 = nums[i], o2 = nums[j];
                temp.clear();
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        temp.push_back(nums[k]);
                    }
                }
                ops.clear();
                ops.push_back(o1 + o2);
                ops.push_back(o1 - o2);
                ops.push_back(o2 - o1);
                ops.push_back(o1 * o2);
                if (o2 != 0)
                    ops.push_back(o1 / o2);
                if (o1 != 0)
                    ops.push_back(o2 / o1);
                for (auto&& op : ops) {
                    temp.push_back(op);
                    bool res = bt(temp);
                    if (res)
                        return true;
                    temp.erase(temp.end() - 1);
                }
            }
        }
        return false;
    }
};

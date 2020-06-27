#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums)
    {
        int cur_min = 15, cur_max = -1;
        unordered_set<int> marked;
        for (auto&& item : nums) {
            if (item == 0)
                continue;
            if (marked.count(item) > 0)
                return false;
            marked.insert(item);
            if (item < cur_min)
                cur_min = item;
            if (item > cur_max)
                cur_max = item;
        }
        return abs(cur_max - cur_min) <= 4;
    }
};

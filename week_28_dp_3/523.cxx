#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    typedef unordered_map<int, int> MAP;

    bool checkSubarraySum(vector<int>& nums, int k)
    {
        MAP map;
        k = abs(k);
        map[0] = -1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0) {
                sum %= k;
            }
            if (map.count(sum) > 0 && map[sum] < i - 1)
                return true;
            if (map.count(sum) == 0)
                map[sum] = i;
        }
        return false;
    }
};

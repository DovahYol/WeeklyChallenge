#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int N = nums.size();
        vector<int> dp(N + 1, 1);
        dp[0] = 0;
        int ans = 0;
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                if (nums[i - 1] > nums[j - 1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (ans < dp[i])
                ans = dp[i];
        }

        return ans;
    }
};

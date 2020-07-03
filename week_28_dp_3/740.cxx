#include <vector>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int N = 10001;
        vector<int> counter(N, 0);
        for (auto&& item : nums) {
            counter[item]++;
        }
        vector<int> dp(N, 0);
        dp[0] = 0;
        dp[1] = counter[1];
        for (int i = 2; i < N; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + counter[i] * i);
        }

        return dp[N - 1];
    }
};

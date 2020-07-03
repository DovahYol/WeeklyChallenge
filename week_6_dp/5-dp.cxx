#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        if(s.size() <= 1) return s;
        int N = s.size();
        vector<vector<bool>> dp(N, vector<bool>(N + 1));
        int max_j = -1, max_i = -1;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j + i <= N; j++) {
                if (i == 1) {
                    dp[j][i] = true;
                } else if (i == 2) {
                    dp[j][i] = s[j] == s[j + i - 1];
                } else {
                    dp[j][i] = dp[j + 1][i - 2] && s[j] == s[j + i - 1];
                }
                if(dp[j][i] && max_i < i){
                    max_i = i;
                    max_j = j;
                }
            }
        }
        return s.substr(max_j, max_i);
    }
};

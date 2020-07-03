#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int N = s.size();
        vector<bool> dp(N + 1);
        dp[0] = true;
        set<string> myDict(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && myDict.count(s.substr(j, i - j)) > 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};

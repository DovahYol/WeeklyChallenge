#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        t.insert(0, " ");
        int N = t.size();
        vector<vector<int>> dic(N, vector<int>(26, -1));
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j > i; j--) {
                dic[i][t[j] - 'a'] = j;
            }
        }

        int i = 0;
        for (auto&& item : s) {
            i = dic[i][item - 'a'];
            if (i < 0)
                return false;
        }

        return true;
    }
};

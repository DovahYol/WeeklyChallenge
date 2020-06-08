#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<char> stk;
    unordered_map<char, int> counter;
    vector<string> ans;

    vector<string> permutation(string S)
    {
        for (int i = 0; i < S.size(); i++) {
            counter[S[i]]++;
        }
        bt();
        return ans;
    }

    void bt()
    {
        bool last = true;
        for (auto& item: counter) {
            if(item.second == 0) continue;
            last = false;
            stk.push_back(item.first);
            item.second--;
            bt();
            stk.erase(stk.end() - 1);
            item.second++;
        }

        if (last) {
            string s(stk.begin(), stk.end());
            ans.push_back(s);
        }
    }
};

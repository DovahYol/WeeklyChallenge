#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_set<char> aeiou = { 'a', 'e', 'i', 'o', 'u' };

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        unordered_set<string> table_c;
        unordered_map<string, string> table_d;
        unordered_map<string, string> table_f;
        for (int i = wordlist.size() - 1; i >= 0; i--) {
            string real = wordlist[i];
            table_c.insert(real);
            for (int j = 0; j < wordlist[i].size(); j++) {
                if (wordlist[i][j] < 'a')
                    wordlist[i][j] += 32;
            }
            table_d[wordlist[i]] = real;
            for (int j = 0; j < wordlist[i].size(); j++) {
                if (aeiou.count(wordlist[i][j])) {
                    wordlist[i][j] = '*';
                }
            }
            table_f[wordlist[i]] = real;
        }
        vector<string> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (table_c.count(queries[i])) {
                ans.push_back(queries[i]);
                continue;
            }
            for (int j = 0; j < queries[i].size(); j++) {
                if (queries[i][j] < 'a')
                    queries[i][j] += 32;
            }
            if (table_d.count(queries[i])) {
                ans.push_back(table_d[queries[i]]);
                continue;
            }
            for (int j = 0; j < queries[i].size(); j++) {
                if (aeiou.count(queries[i][j])) {
                    queries[i][j] = '*';
                }
            }
            if (table_f.count(queries[i])) {
                ans.push_back(table_f[queries[i]]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};

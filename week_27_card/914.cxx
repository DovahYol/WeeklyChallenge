#include <map>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck)
    {
        map<int, int> dic;
        for (int i = 0; i < deck.size(); i++) {
            dic[deck[i]]++;
        }
        auto iter = dic.begin();
        int c1 = iter->second;
        iter++;
        if(iter == dic.end()) return c1 >= 2;
        int c2 = iter->second;
        int temp = gcd(c1, c2);
        for (iter++; iter != dic.end(); iter++) {
            temp = gcd(temp, iter->second);
        }
        return temp >= 2;
    }
};

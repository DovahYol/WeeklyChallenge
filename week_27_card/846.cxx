#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W)
    {
        map<int, int> dic;
        for (auto&& item : hand) {
            dic[item]++;
        }
        while (!dic.empty()) {
            int key = dic.begin()->first;
            for (int i = 0; i < W; i++) {
                int cur = key + i;
                if (dic[cur] <= 0)
                    return false;
                dic[cur]--;
                if (dic[cur] == 0) {
                    dic.erase(cur);
                }
            }
        }
        return true;
    }
};

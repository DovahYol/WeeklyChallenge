#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> counter;
    int ans = 0;

    int numTilePossibilities(string tiles)
    {
        for(int i = 0; i < tiles.size(); i++) {
            counter[tiles[i]]++;
        }

        bt();

        return ans;
    }

    void bt() {
        for (auto& item: counter) {
            if(item.second == 0) continue;
            ans++;
            item.second--;
            bt();
            item.second++;
        }
    }
};

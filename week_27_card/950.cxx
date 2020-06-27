#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck)
    {
        deque<int> tmp;
        sort(deck.begin(), deck.end());
        tmp.push_back(deck.back());
        for (int i = deck.size() - 2; i >= 0; --i) {
            tmp.push_front(tmp.back());
            tmp.pop_back();
            tmp.push_front(deck[i]);
        }
        vector<int> ans(tmp.begin(), tmp.end());
        return ans;
    }
};

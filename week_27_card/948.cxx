#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P)
    {
        sort(tokens.begin(), tokens.end());
        int power = P;
        int score = 0;
        int j = tokens.size();
        for (int i = 0; i < tokens.size(); i++) {
            if (power < tokens[i]) {
                if (score > 0 && j >= i + 2) {
                    j--;
                    power += tokens[j];
                    score--;
                } else
                    break;
            }
            power -= tokens[i];
            score++;
        }
        return score;
    }
};

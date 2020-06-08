#include <vector>

class Solution {
public:
    int ans = 0, N;
    vector<int> counter;
    bool first = true;

    int countNumbersWithUniqueDigits(int n)
    {
        counter.resize(10, 1);
        N = n;
        bt();
        return ++ans;
    }

    void bt()
    {
        if (N == 0) {
            return;
        }
        for (int i = 0; i < counter.size(); i++) {
            if (counter[i] == 0 || (first && i == 0))
                continue;
            counter[i]--;
            N--;
            first = false;
            ans++;
            bt();
            counter[i]++;
            N++;
            first = true;
        }
    }
};

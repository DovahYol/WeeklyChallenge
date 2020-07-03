#include <vector>

using namespace std;

class Solution {
public:
    vector<int> v;
    int waysToStep(int n)
    {
        if (n <= 2)
            return n;
        if (n == 3)
            return 4;
        int a = 1, b = 2, c = 4;
        int ans = 0;
        for (int i = 4; i <= n; i++) {
            ans = a;
            ans = (ans + b) % 1000000007;
            ans = (ans + c) % 1000000007;
            a = b;
            b = c;
            c = ans;
        }
        return ans;
    }
};

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int temp = -1;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') { 
                if (temp != -1) ans = temp;
                temp = -1;
                continue;
            }
            if (temp == -1) temp = 1;
            else temp++;
        }
        if (temp != -1) ans = temp;
        return ans;
    }
};

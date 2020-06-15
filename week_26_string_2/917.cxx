#include <string>
using namespace std;

class Solution {
public:
    bool aZ(char& t) {
        return (t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z');
    }

    string reverseOnlyLetters(string S)
    {
        for(int i = 0, j = S.size() - 1; i < j; ) {
            if (aZ(S[i]) && aZ(S[j])) {
                int temp = S[i];
                S[i] = S[j];
                S[j] = temp;
                i++;
                j--;
            } else if(aZ(S[i])) {
                j--;
            } else if(aZ(S[j])) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        
        return S;
    }
};

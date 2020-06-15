#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int max_len = max(num1.size(), num2.size());
        string pad_num1(max_len, '0');
        string pad_num2(max_len, '0');
        int j = 0;
        for(int i = max_len - num1.size(); i < max_len; i++) {
            pad_num1[i] = num1[j++];
        }
        j = 0;
        for(int i = max_len - num2.size(); i < max_len; i++) {
            pad_num2[i] = num2[j++];
        }
        int carry = 0;
        for(int i = max_len - 1; i >=0; i--) {
            int cur = pad_num1[i] + pad_num2[i] + carry - 2 * '0';
            pad_num2[i] = (cur % 10) + '0'; 
            carry = cur / 10;
        }
        if (carry != 0) return '1' + pad_num2;
        else return pad_num2;
    }
};

#include <string>
using namespace std;

class Solution {
public:
    typedef long long LL;

    bool isAdditiveNumber(string num)
    {
        int N = num.size();
        if (N < 3)
            return false;
        for (int i = 1; i < N; i++) {
            if (num[0] == '0' && i > 1) {
                break;
            }

            for (int j = i + 1; j < N; j++) {
                int first = 0;
                int second = i;
                int third = j;
                if (num[second] == '0' && third - second > 1) {
                    break;
                }
                while (true) {
                    string str_item1 = num.substr(first, second - first);
                    string str_item2 = num.substr(second, third - second);
                    LL item1 = stoll(str_item1, 0, 10);
                    LL item2 = stoll(str_item2, 0, 10);
                    LL item3 = item1 + item2;
                    string str_item3 = to_string(item3);
                    int str_item3_size = str_item3.size();
                    if (num.substr(third).rfind(str_item3, 0) != string::npos) {
                        if (str_item3_size == N - third) {
                            return true;
                        }
                        first = second;
                        second = third;
                        third += str_item3_size;
                    } else
                        break;
                }
            }
        }

        return false;
    }
};

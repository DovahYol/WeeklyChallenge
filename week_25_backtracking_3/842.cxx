#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    typedef long long LL;
    vector<int> splitIntoFibonacci(string S)
    {
        int N = S.size();
        vector<int> ans;
        for (int i = 1; i < N; i++) {
            if (S[0] == '0' && i > 1)
                break;
            for (int j = i + 1; j < N; j++) {
                int first = 0;
                int second = i;
                int third = j;
                if (S[i] == '0' && (j - i) > 1)
                    break;
                ans.clear();
                try {
                    ans.push_back(stoi(S.substr(0, i), 0, 10));
                    ans.push_back(stoi(S.substr(i, j - i), 0, 10));
                } catch (...) {
                    break;
                }
                while (true) {
                    string str_first = S.substr(first, second - first);
                    string str_second = S.substr(second, third - second);
                    int first_item, second_item, third_item;
                    try {
                        first_item = stoi(str_first, 0, 10);
                        second_item = stoi(str_second, 0, 10);
                    } catch (...) {
                        break;
                    }
                    LL temp_third = static_cast<LL>(first_item) + second_item;
                    if (temp_third < 0)
                        break;
                    third_item = static_cast<int>(temp_third);
                    string str_third = to_string(third_item);
                    int third_size = str_third.size();
                    int counter = 0;
                    while (counter < third_size && (counter + third) < N && str_third[counter] == S[counter + third]) {
                        counter++;
                    }
                    if (counter == third_size) {
                        ans.push_back(third_item);
                        if (counter == N - third) {
                            return ans;
                        }
                        first = second;
                        second = third;
                        third += counter;
                    } else {
                        break;
                    }
                }
            }
        }
        ans.clear();
        return ans;
    }
};

// Thanks for https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
// Which gave me such a comprehensive explanation.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;
        int max_c = -1, max_p = -1;
        int N = 2 * s.size() + 1;
        vector<int> P(N);
        int C = 1;
        P[0] = 0;
        P[1] = 1;
        for (int i = 2; i < N; i++) {
            int L = C - P[C];
            int R = C + P[C];
            int dist2R = R - i;
            int mirror = 2 * C - i;
            bool expand = false;
            if (dist2R >= 0) {
                if (mirror - P[mirror] > L || (mirror - P[mirror] == L && R == N - 1)) {
                    P[i] = P[mirror];
                } else if (mirror - P[mirror] == L) {
                    P[i] = P[mirror];
                    expand = true;
                } else if (mirror - P[mirror] < L) {
                    P[i] = dist2R;
                    expand = true;
                } else {
                    cout << "won't reach here" << endl;
                }
            } else {
                P[i] = 0;
                expand = true;
            }

            if (expand) {
                while (true) {
                    int maybeL = i - P[i] - 1;
                    int maybeR = i + P[i] + 1;
                    if (maybeR <= N - 1 && maybeL >= 0 && (maybeR % 2 == 0 || s[maybeR / 2] == s[maybeL / 2])) {
                        P[i]++;
                    } else
                        break;
                }
            }

            if (i + P[i] > R) {
                C = i;
            }

            if (max_p < P[i]) {
                max_p = P[i];
                max_c = i;
            }
        }

        return s.substr((max_c - max_p) / 2, max_p);
    }
};

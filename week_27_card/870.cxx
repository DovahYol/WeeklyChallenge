#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B)
    {
        map<double, int> ad, bd;
        const double diff = 0.000001;
        double ha = diff;
        for (int i = 0; i < A.size(); i++) {
            ad[A[i] + ha] = -1;
            ha += diff;
        }
        ha = diff;
        for (int i = 0; i < B.size(); i++) {
            bd[B[i] + ha + 0.5] = i;
            ha += diff;
        }
        auto iterA = ad.begin();
        auto iterB = bd.begin();
        for (; iterA != ad.end(); iterA++) {
            if (iterB != bd.end() && iterA->first > iterB->first) {
                iterA->second = iterB->second;
                iterB++;
            }
        }
        iterA = ad.begin();
        while (iterB != bd.end()) {
            while (iterA->second != -1)
                iterA++;
            iterA->second = iterB->second;
            iterB++;
        }
        for (iterA = ad.begin(); iterA != ad.end(); iterA++) {
            A[iterA->second] = floor(iterA->first);
        }
        return A;
    }
};

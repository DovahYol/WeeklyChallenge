#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int N = nums.size();
        if(N < 3) return false;
        vector<int> arr(N);
        arr[0] = 0x7FFFFFFF;
        for (int i = 1; i < N; i++) {
            arr[i] = min(arr[i - 1], nums[i - 1]);
        }
        for (int i = N - 1; i >= 0; i--) {
            while(!stk.empty() && stk.top() <= arr[i]) {
                stk.pop();
            }
            if(nums[i] > arr[i] && !stk.empty() && stk.top() < nums[i]) return true;
            stk.push(nums[i]);
        }
        return false;
    }
    
};

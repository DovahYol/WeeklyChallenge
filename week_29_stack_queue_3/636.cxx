#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    void parse(string& log, int& fid, bool& isStart, int& timestamp)
    {
        size_t pos1 = log.find(":");
        size_t pos2 = log.rfind(":");
        fid = stoi(log.substr(0, pos1));
        isStart = log.substr(pos1 + 1, pos2 - pos1 - 1) == "start";
        timestamp = stoi(log.substr(pos2 + 1));
    }

public:
    vector<int> exclusiveTime(int n, vector<string>& logs)
    {
        vector<int> ans(n);
        stack<int> stk;
        int callerStartTime = -1;

        for (int i = 0; i < logs.size(); i++) {
            string& log = logs[i];
            int fid;
            bool isStart;
            int timestamp;
            parse(log, fid, isStart, timestamp);
            if (isStart) {
                if (!stk.empty()) {
                    ans[stk.top()] += timestamp - callerStartTime;
                }
                stk.push(fid);
                callerStartTime = timestamp;
            } else {
                ans[stk.top()] += timestamp - callerStartTime + 1;
                stk.pop();
                callerStartTime = timestamp + 1;
            }
        }
        return ans;
    }
};

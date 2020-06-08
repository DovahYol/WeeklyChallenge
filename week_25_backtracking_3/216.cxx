#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> m_ans;
    int m_k;
    int m_n;

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
	m_k = k;
	m_n = n;

	for (int i = 1; i < 10; i++) {
	    bt(0, i);
	}

	return m_ans;
    }

    void bt(int acc, int end, vector<int> working_ans = {})
    {
	int cur = acc + end;

	if (working_ans.size() + 1 > m_k || cur > m_n) {
	    return;
	}

	working_ans.push_back(end);

	if (working_ans.size() == m_k && cur == m_n) {
	    m_ans.push_back(working_ans);
	    return;
	}

	for (int i = 1; i < end; i++) {
	    bt(cur, i, working_ans);
	}
    }
};

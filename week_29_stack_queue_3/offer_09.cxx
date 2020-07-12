#include <stack>

using namespace std;

class CQueue {
private:
    stack<int> m_s1;
    stack<int> m_s2;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        while(!m_s1.empty()) {
            m_s2.push(m_s1.top());
            m_s1.pop();
        }
        m_s1.push(value);
        while(!m_s2.empty()) {
            m_s1.push(m_s2.top());
            m_s2.pop();
        }
    }

    int deleteHead()
    {
        if(m_s1.empty()) {
            return -1;
        }
        int ans = m_s1.top();
        m_s1.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

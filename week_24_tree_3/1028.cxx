/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <vector>

class Solution {
private:
    typedef TreeNode TN;
    struct P {
        int d;
        TN* t;
    };
public:
    TreeNode* recoverFromPreorder(string S) {
        char* cs = new char[S.size() + 1];
        char* todelete = cs;
        strcpy(cs, S.c_str());
        vector<P> v;
        while(true) {
            int count=0;
            while(*cs == '-') {
                count++;
                cs++;
            }
            P p;
            p.d = count;
            p.t = new TreeNode(atoi(cs));
            while(*cs != '-' && *cs != '\0') cs++;
            for(int i = v.size() - 1; i >= 0; i--) {
                P& cur = v[i];
                if(cur.d == p.d) {
                    v[i-1].t->right = p.t;
                    break;
                }else if(cur.d == p.d - 1) {
                    cur.t->left = p.t;
                    break;
                }
            }
            v.push_back(p);
            if(*cs == '\0') break;
        }
        delete []todelete;
        return v[0].t;
    }
};
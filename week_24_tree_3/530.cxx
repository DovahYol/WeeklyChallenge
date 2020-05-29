/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>

class Solution {
private:
    const int MAX = 0x7FFFFFFF;
    typedef TreeNode TN;
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TN *> s;
        int pre = -1, ret = MAX;
        while(root != NULL || !s.empty()) {
            while(root != NULL) {
                s.push(root);
                root = root->left;
            }
            TN* t = s.top(); s.pop();
            if(pre != -1) ret = min(ret, t->val - pre);
            pre = t->val;
            root = t->right;
        }
        return ret;
    }
};
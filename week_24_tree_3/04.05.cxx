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
    typedef TreeNode TN;
public:
    bool isValidBST(TreeNode* root) {
        std::stack<TN *> s;
        int pre;
        bool isFirst = true;
        while(root != NULL || !s.empty()) {
            while(root != NULL) {
                s.push(root);
                root = root->left;
            }
            TN *t = s.top(); s.pop();
            if(!isFirst && t->val <= pre) return false;
            isFirst = false;
            pre = t->val;
            root = t->right;
        }
        return true;
    }
};
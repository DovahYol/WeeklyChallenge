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
    TreeNode* convertBST(TreeNode* root) {
        std::stack<TN *> s;
        TN *ret = root, *pre = NULL;
        while(root != NULL || !s.empty()) {
            while(root != NULL) {
                s.push(root);
                root = root->right;
            }
            TN* t = s.top(); s.pop();
            if(pre != NULL) t->val += pre->val;
            pre = t;
            root = t->left;
        }

        return ret;
    }
};
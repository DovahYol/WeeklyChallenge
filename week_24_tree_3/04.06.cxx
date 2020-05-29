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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        std::stack<TN *> s;
        bool found = false;
        while(root != NULL || !s.empty()) {
            while(root != NULL) {
                s.push(root);
                root = root->left;
            }
            TN *t = s.top(); s.pop();
            if(found) return t;
            if(t == p) found = true;
            root = t->right;
        }

        return NULL;
    }
};
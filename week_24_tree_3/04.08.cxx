/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    typedef TreeNode TN;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TN *l = lowestCommonAncestor(root->left, p, q);
        TN *r = lowestCommonAncestor(root->right, p, q);
        if(l != NULL && r != NULL) return root;
        if(l != NULL) return l;
        else return r;
    }
};
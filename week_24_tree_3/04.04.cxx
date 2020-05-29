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
public:
    int blc(TreeNode* root) {
        int l, r;
        if(root == NULL) return 0;
        l = blc(root->left);
        r = blc(root->right);
        if(l == -1 || r == -1) {
            return -1;
        }
        if(abs(l - r) > 1) {
            return -1;
        } else {
            return max(l, r) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return blc(root) != -1;
    }
};
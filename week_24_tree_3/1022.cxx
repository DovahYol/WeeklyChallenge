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
    int sum = 0;
    int mod = pow(10, 9) + 7;    

    void pt(TN* r, int acc) {
        if(r == NULL) return;
        int ret = (acc << 1) + r->val;
        if(r->left == NULL && r->right == NULL) {
            sum += ret % mod;
            return;
        }
        pt(r->left, ret);
        pt(r->right, ret);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        pt(root, 0);
        return sum;
    }
};
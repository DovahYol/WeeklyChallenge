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
    void pdd(TN* p_root, int& p_min, int& p_max, int& p_res) {
        if(p_root == NULL) {
            p_min = 100001;
            p_max = -1;
            // not used
            p_res = -1;
            return;
        }
        int l_min, l_max, l_res, r_min, r_max, r_res;
        int val = p_root->val;
        pdd(p_root->left, l_min, l_max, l_res);
        pdd(p_root->right, r_min, r_max, r_res);
        p_min = min(l_min, r_min);
        p_max = max(l_max, r_max);
        if(p_min == 100001 && p_max == -1) {
            p_res = -1;
        } else {
            p_res = max(abs(val - p_min), abs(val - p_max));
        }
        p_min = min(p_min, val);
        p_max = max(p_max, val);
        p_res = max(l_res, p_res);
        p_res = max(r_res, p_res);
    }
    int maxAncestorDiff(TreeNode* root) {
        int p_min, p_max, p_res;
        pdd(root, p_min, p_max, p_res);
        return p_res;
    }
};
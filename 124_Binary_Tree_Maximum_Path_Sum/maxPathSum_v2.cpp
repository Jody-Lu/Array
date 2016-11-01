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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxSumHelper(res, root);
        return res;
    }
private:
    int maxSumHelper(int& res, TreeNode* root) {
        if(!root) { return 0; }
        int lMax = maxSumHelper(res, root->left);
        int rMax = maxSumHelper(res, root->right);
        int maxSingle = max(max(lMax, rMax) + root->val, root->val);
        int maxTop = max(maxSingle, lMax + root->val + rMax);
        res = max(res, maxTop);
        return maxSingle;
    }
};
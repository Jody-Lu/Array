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
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return tryRob(root, l, r);
    }

private:
    int tryRob(TreeNode* root, int& l, int& r) {
        if(!root) { return 0; }

        // ll, lr, rl, rr are gradchildren of root
        int ll = 0, lr = 0, rl = 0, rr = 0;
        
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);

        // either taking root and its grandchildren or root's children
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};

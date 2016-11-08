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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        dfs(res, root);
        return res;
    }
private:

    void dfs(int& res, TreeNode* root) {
        if(!root) { return; }
        if(root->left && !(root->left->left) && !(root->left->right)) {
            res += root->left->val;
        }

        dfs(res, root->left);
        dfs(res, root->right);
    }
};
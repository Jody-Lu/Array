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
    int longestConsecutive(TreeNode* root) {
        return search(0, NULL, root);
    }

    int search(int len, TreeNode* parent, TreeNode* root) {
        if(!root) { return len; }
        len = (parent && (parent->val + 1) == root->val)? (len + 1) : 1;
        return max(len, max(search(len, root, root->left), search(len, root, root->right)));
    }

};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// O(lg(n))
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while((p->val - root->val) * (q->val - root->val) > 0) {
            if(p->val > root-> val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
};

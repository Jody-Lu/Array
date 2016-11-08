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
        if(!root) { return 0; }
        int res = 1;
        longestConsecutiveHelper(res, 1, root);
        return res;
    }

    void longestConsecutiveHelper(int& res, int path, TreeNode* root) {
        res = max(res, path);

        if(root->left) {
            if((root->left->val - root->val) == 1) {
                longestConsecutiveHelper(res, path + 1, root->left);
            }
            else {
                // path recount from 1
                longestConsecutiveHelper(res, 1, root->left);
            }
        }

        if(root->right) {
            if((root->right->val - root->val) == 1) {
                longestConsecutiveHelper(res, path + 1, root->right);
            }
            else {
                longestConsecutiveHelper(res, 1, root->right);
            }
        }
    }

};
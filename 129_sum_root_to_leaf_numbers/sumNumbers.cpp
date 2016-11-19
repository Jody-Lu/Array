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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        sumNumbersHelper(res, 0, root);
        return res;
    }

private:
    void sumNumbersHelper(int& res, int num, TreeNode* root) {
        if(!root) {
            return;
        }

        num = num * 10 + root->val;

        if(!root->left && !root-> right) {
            res += num;
            return;
        }

        sumNumbersHelper(res, num, root->left);
        sumNumbersHelper(res, num, root->right);
    }
};
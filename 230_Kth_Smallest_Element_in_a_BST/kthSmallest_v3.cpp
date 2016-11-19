class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int numL = countNode(root->left);
        while(k != numL + 1) {
            if(k < numL + 1) {
                root = root->left;
            }
            else {
                root = root->right;
                k -= (numL + 1);
            }
            numL = countNode(root->left);
        }

        return root->val;
    }

private:
    int countNode(TreeNode* node) {
        return (node)? 1 + countNode(node->left) + countNode(node->right): 0;
    }
};
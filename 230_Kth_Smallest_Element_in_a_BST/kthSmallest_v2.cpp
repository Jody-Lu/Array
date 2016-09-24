class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int numL = countNode(root -> left);
        if(k == (1 + numL)) return root -> val;
        else if(k > (numL + 1)) return kthSmallest(root -> right, k - (numL + 1));
        else return kthSmallest(root -> left, k);
    }
    int countNode(TreeNode* root) {
        if(!root) return 0;
        return 1 + countNode(root -> left) + countNode(root -> right);
    }
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        long res = root->val;
        while(root) {
            if(abs(target - root->val) < abs(target - res)) {
                res = root->val;
            }
            if(target > root->val) {
                root = root->right;
            }
            else {
                root = root-> left;
            }
        }
        return res;
    }
};
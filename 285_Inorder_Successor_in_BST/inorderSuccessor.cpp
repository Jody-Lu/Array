class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right) {
            return leftMost(p->right);
        }
        TreeNode* suc = NULL;
        while(root) {
            if(p->val < root->val) {
                suc = root; // since successor is always bigger than p in inorder traversal
                root = root->left;
            }
            else if(p -> val > root-> val){
                root = root->right;
            }
            else { // root == p
                break;
            }
        }
        return suc;
    }
private:
    TreeNode* leftMost(TreeNode* p) {
        while(p->left) {
            p = p->left;
        } 
        return p;
    }
};
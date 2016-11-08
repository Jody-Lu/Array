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
        stack<TreeNode*> st;
        
        while(root) {
            st.push(root);
            root = root->left;
        }
        
        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            
            if(curr->left && !curr->left->left && !curr->left->right) {
                res += curr->left->val;
            }
            
            TreeNode* node = curr->right;
            while(node) {
                st.push(node);
                node = node->left;
            }
        }
        
        return res;
    }
};
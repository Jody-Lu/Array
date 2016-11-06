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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        
        while(root) {
            st.push(root);
            root = root->left;
        }
        
        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            res.push_back(curr->val);
            TreeNode* node = curr->right;
            while(node) {
                st.push(node);
                node = node->left;
            }
        }
        
        return res;
    }
};
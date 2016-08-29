#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
  	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void recoverTree(TreeNode* root) {
            inorder(root);
            sort(in.begin(), in.end());
            for(int i = 0; i < tree.size(); i++) {
                tree[i] -> val = in[i];
            }
        }
    private:
        void inorder(TreeNode* root) {
            if(!root) return;
            inorder(root -> left);
            in.push_back(root -> val);
            tree.push_back(root);
            inorder(root -> right);
        }
        vector<TreeNode*> tree; 
        vector<int> in;
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(0);
    root -> left = new TreeNode(1);
    sol.recoverTree(root);
}

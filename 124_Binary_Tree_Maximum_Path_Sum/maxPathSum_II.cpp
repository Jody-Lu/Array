#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNOde* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// maxPath starts from root and ends at any node
class Solution {
    public:
        int maxPathSum2(TreeNode* root) {
            if(!root) {
                return 0;
            }

            int lMax = maxPathSum2(root->left);
            int rMax = maxPathSum2(root->right);

            return max(0, max(lMax, rMax)) + root->val;
        }
};

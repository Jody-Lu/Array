#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
    	bool isSymmetric(TreeNode* root) {
            return ifSymmetric(root, root);
    	}
    private:
        bool ifSymmetric(TreeNode* a, TreeNode* b) {
            if(!a || !b) return a == b;
            return a -> val == b -> val && \
                   ifSymmetric(a -> left, b -> right) && \
                   ifSymmetric(a -> right, b -> left);
        }
};

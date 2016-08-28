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
    	bool isBalanced(TreeNode* root) {
            if(!root) return true;
            if(abs(height(root -> left) - height(root -> right)) > 1)
                return false;
            else {
                return isBalanced(root -> left) && isBalanced(root -> right);
            }
    	}
    private:
        int height(TreeNode* node) {
            return node? 1 + max(height(node -> left), height(node -> right)) : 0;
        }
};

int main() {
    return 0;
}

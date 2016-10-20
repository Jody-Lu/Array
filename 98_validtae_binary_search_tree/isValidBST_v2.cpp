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
        bool isValidBST(TreeNode* root) {
            TreeNode* prev = NULL;
            return validate(root, prev);
        }
    private:
        bool validate(TreeNode* root, TreeNode*& prev) {
                if(!root) return true;
                if(!validate(root->left, prev)) return false;
                // prev: before setting to current is previous
                if(prev != NULL && prev -> val >= root -> val) return false; //prev
                prev = root; // current
                return validate(root->right, prev);
        }
};

int main() {
    return 0;
}

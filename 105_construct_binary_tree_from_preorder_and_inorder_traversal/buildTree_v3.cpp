#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int preIndex = 0;
            return dfs(inorder, preorder, 0, inorder.size() - 1, preIndex);
        }
    private:
        TreeNode* dfs(vector<int>& in, vector<int>& pre, int inStrt, int inEnd, int& preIndex) {

            if(inStrt > inEnd)
                return NULL;

            // Find the root at this stage.
            TreeNode* tNode = new TreeNode(pre[preIndex++]);

            // At this stage, this node is a leaf node.
            if(inStrt == inEnd)
                return tNode;

            // Not a leaf node, find the left and right subtree
            // We define a search function here to help us find the root in inOrder
            int inIndex = search(in, inStrt, inEnd, tNode->val);

            tNode -> left = dfs(in, pre, inStrt, inIndex - 1, preIndex);
            tNode -> right = dfs(in, pre, inIndex + 1, inEnd, preIndex);
            return tNode;
        }
        int search(vector<int>& v, int strt, int end, int target) {
            int i;
            for(i = strt; i <= end; i++) {
                if(v[i] == target)
                    return i;
            }
            return -1;
        }

};

int main() {
    return 0;
}

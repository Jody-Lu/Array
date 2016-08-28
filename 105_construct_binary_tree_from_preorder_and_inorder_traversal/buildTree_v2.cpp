#include <iostream>
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
    	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return helper(preorder, inorder, 0, inorder.size() - 1);
    	}
    private:
        TreeNode* helper(vector<int>& in, vector<int>& pre, int inStrt, int inEnd) {
            static int preIndex = 0;

            if(inStrt > inEnd)
                return NULL;

            TreeNode* tNode = new TreeNode(pre[preIndex++]);

            if(inStrt == inEnd) 
                return tNode;

            int inIndex = search(in, inStrt, inEnd, tNode -> val);

            tNode -> left = helper(in, pre, inStrt, inIndex - 1);
            tNode -> right = helper(in, pre, inIndex + 1, inEnd);
            return tNode;
        }

        int search(vector<int>& v, int strt, int end, int val) {
            int i;
            for(i = strt; i <= end; i++) {
                if(v[i] == val)
                    break;
            }
            return i;
        }
};


int main() {
    return 0;
}

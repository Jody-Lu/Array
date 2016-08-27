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
    	bool isSameTree(TreeNode* p, TreeNode* q) {
            /* 1. both are empty, return true. */
            if(!p && !q) return true;

            /* 2. both are non-empty. */
            if(p && q)
                return p -> val == q -> val && \
            		   isSameTree(p -> left, q -> left) && \
                       isSameTree(p -> right, q -> right);
            /* 3. one empty, one not*/
            else return false;

    	}
};

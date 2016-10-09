#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	public:
    	int maxPathSum(TreeNode* root) {
            int res = INT_MIN;
            dfs(res, root);
            return res;
    	}
    private:
        int dfs(int& res, TreeNode* root) {
            if(!root) return 0;

            int sum = root->val;
            int lMax = dfs(res, root->left);
            int rMax = dfs(res, root->right);

            if(lMax > 0)
                sum += lMax;

            if(rMax > 0)
                sum += rMax;

            res = max(res, sum);
            return max(0, max(lMax, rMax)) + root->val;
        }

};

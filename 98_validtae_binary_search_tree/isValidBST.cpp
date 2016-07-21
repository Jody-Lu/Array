#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};


class Tree
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if(inorder.size() == 0)
            return NULL;

        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}
	// preorder
	void pre_traversal(TreeNode* p)
	{
		if(!p) return;
		cout << p -> val << " ";
		pre_traversal(p -> left);
		pre_traversal(p -> right);
	}
	// inorder
	void in_traversal(TreeNode* p)
	{
		if(!p) return;
		in_traversal(p -> left);
		cout << p -> val << " ";
		in_traversal(p -> right);
	}
private:
	TreeNode* helper(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2)
	{
		if(l1 >= r1) return NULL;

		TreeNode* root = new TreeNode(preorder[l1]);

		int i;
		for(i = l2; i < r2; ++i)
		{
			if(inorder[i] == preorder[l1])
				break;
		}

		if(i > l2)
		{
			int len = i - l2;
			root -> left = helper(preorder, l1 + 1, l1 + 1 + len, inorder, l2, i);
		}
		else
		{
			root -> left = NULL;
		}

		if(i + 1 < r2)
		{
			int len = r2 - i - 1;
			root->right = helper(preorder, r1 - len, r1, inorder, i + 1, r2);
		}
		else
		{
			root->right = NULL;
		}

		return root;

	}

};

class Solution
{
public:
	bool isValidBST(TreeNode* root)
	{
		vector<int> tmp;
		traverse(root, tmp);
		for(int i = 1; i < tmp.size(); ++i)
		{
			if(tmp[i] <= tmp[i - 1]) return false;
		}
		return true;
	}
private:
	void traverse(TreeNode* root, vector<int>& tmp)
	{
		if(!root) return;
		traverse(root -> left, tmp);
		tmp.push_back(root -> val);
		traverse(root -> right, tmp);
	}
};

int main()
{
	int a[] = {1, 1};
	vector<int> preorder(a, a + sizeof(a)/sizeof(*a));
	int b[] = {1, 1};
	vector<int> inorder(b, b + sizeof(b)/sizeof(*b));
	Tree tree;
	Solution sol;
	TreeNode* root = tree.buildTree(preorder, inorder);
	bool result;
	result = sol.isValidBST(root);

	cout << result << endl;

	return 0;
}



#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Tree
{
public:
	TreeLinkNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if(inorder.size() == 0)
            return NULL;

        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}
private:
	TreeLinkNode* helper(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2)
	{
		if(l1 >= r1) return NULL;

		TreeLinkNode* root = new TreeLinkNode(preorder[l1]);

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
	void connect(TreeLinkNode* root)
	{
		vector<vector<TreeLinkNode*> > result = levelOrder(root);
		for(int i = 1; i < result.size(); ++i)
		{
			for(int j = 0; j < result[i].size() - 1; ++j)
			{
				result[i][j] -> next = result[i][j + 1];
			}
		}
	}
private:
	vector<vector<TreeLinkNode*> > levelOrder(TreeLinkNode* root)
	{
		vector<vector<TreeLinkNode*> > result;
		traverse(root, 1, result);
		return result;
	}
	void traverse(TreeLinkNode* root, size_t level, vector<vector<TreeLinkNode*> >& result)
	{
		if(!root) return;

		if(level > result.size())
			result.push_back(vector<TreeLinkNode*>());

		result[level - 1].push_back(root);

		traverse(root -> left, level + 1, result);
		traverse(root -> right, level + 1, result);
	}
};

int main()
{
	int a[] = {1, 2, 4, 5, 3, 6, 7};
	vector<int> preorder(a, a + sizeof(a)/sizeof(*a));
	int b[] = {4, 2, 5, 1, 6, 3, 7};
	vector<int> inorder(b, b + sizeof(b)/sizeof(*b));
	Tree tree;
	Solution sol;
	TreeLinkNode* root = tree.buildTree(preorder, inorder);
	sol.connect(root);
	//cout << root -> left -> next -> val << endl;
	//cout << root -> left -> right -> next -> val << endl;

}
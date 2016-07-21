// constant space required
// perfect binary tree

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}
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
		if(root == NULL || root -> left == NULL)
			return;

		if(root -> left != NULL)
			root -> left -> next = root -> right;

		if(root -> right != NULL && root -> next != NULL)
			root -> right -> next = root -> next -> left;
		else if(root -> right != NULL)
			root -> right -> next = NULL;

		connect(root -> left);
		connect(root -> right);

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
	cout << root -> left -> next -> val << endl;
	cout << root -> left -> right -> next -> val << endl;

}
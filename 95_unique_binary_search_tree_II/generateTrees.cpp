#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution
{
public:
	vector<TreeNode*> generateTrees(int n)
	{
		vector<TreeNode*> Result;
		if(n == 0) return Result;
		else
			return generate(1, n);
	}
private:
	vector<TreeNode*> generate(int begin, int end)
	{
		//cout << "begin: " << begin << " end: " << end << endl;
		vector<TreeNode*> res;
		if(begin > end) res.push_back(NULL);
		if(begin == end) res.push_back(new TreeNode(begin));
		if(begin < end)
		{
			for(int k = begin; k <= end; ++k)
			{
				//cout << "k= " << k << endl;
				vector<TreeNode*> l = generate(begin, k - 1);
				vector<TreeNode*> r = generate(k + 1, end);
				//cout << "lszie: " << l.size() << endl;
				//cout << "rszie: " << r.size() << endl;
				for(int i = 0; i < l.size(); ++i)
				{
					for(int j = 0; j < r.size(); ++j)
					{
						TreeNode* node = new TreeNode(k);
						node -> left = l[i];
						node -> right = r[j];
						res.push_back(node);
					}
				}
			}
		}

		return res;
	}
};

int main()
{
	Solution sol;
	vector<TreeNode*> Result = sol.generateTrees(1);
	cout << Result.size() << endl;
}
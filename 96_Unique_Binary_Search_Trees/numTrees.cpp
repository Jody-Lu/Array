#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int numTrees(int n)
	{
		vector<int> f(n + 1, 0);
		f[0] = 1;
		f[1] = 1;
		for(int i = 2; i <= n; ++i)
		{
			for(int k = 1; k <= i; ++k)
			{
				f[i] += f[k - 1] * f[i - k];
			}
		}
		return f[n];
	}
};

int main()
{
	Solution sol;
	cout << sol.numTrees(3) << endl;
	return 0;
}
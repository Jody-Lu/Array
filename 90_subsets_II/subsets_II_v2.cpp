#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int> > subsetsWithDup(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());

		vector<vector<int> > result;
		vector<int> path;
		dfs(nums, nums.begin(), path, result);
		return result;
	}

private:
	static void dfs(const vector<int>& nums, vector<int>::iterator start,
			vector<int>& path, vector<vector<int> >& result)
	{
		result.push_back(path);

		for(auto i = start; i < nums.end(); ++i)
		{
			if(i != start && *i == *(i-1)) continue;
			path.push_back(*i);
			dfs(nums, i + 1, path, result);
			path.pop_back();
		}
	}
};



int main()
{
	Solution sol;
	int arr[] = {1, 1, 2};
	vector<vector<int> > result;
	vector<int> nums(arr, arr+(sizeof(arr)/sizeof(*arr)));
	result = sol.subsetsWithDup(nums);

	for(vector<vector<int> >::iterator it = result.begin();
		it != result.end();
		it++)
	{
		cout << "[";
		for(vector<int>::iterator itt = (*it).begin();
			itt != (*it).end();
			itt++)
		{
			cout << *itt << ",";
		}
		cout << "]" << endl;
	}

}

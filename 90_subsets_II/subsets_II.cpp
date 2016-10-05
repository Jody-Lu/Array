#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int> > subsetsWithDup(vector<int>& nums)
	{
		vector<vector<int> > result;
		vector<int> path;

		sort(nums.begin(), nums.end());
		subsets(nums, path, 0, result);

		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
private:
	static void subsets(const vector<int>& nums, vector<int> &path, int step,
			vector<vector<int> >& result)
	{

		if(step == nums.size())
		{
			result.push_back(path);
			return;
		}

		// not choose nums[step]
		subsets(nums, path, step + 1, result);
		//choose nums[step]
		path.push_back(nums[step]);
		subsets(nums, path, step + 1, result);

		path.pop_back();
	}
};





int main()
{
	Solution sol;
	int arr[] = {1, 2, 2};
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

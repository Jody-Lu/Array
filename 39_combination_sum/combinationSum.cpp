#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int> > result;
		//if(candidates.size() == 1 && candidates[0] > target) return result;
		sort(candidates.begin(), candidates.end());
		vector<int> stack;
		dfs(stack, result, candidates, target);

		for(int i = 0; i < result.size(); i++)
		{
			sort(result[i].begin(), result[i].end());
		}

		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
private:
	// put each element into recurse and into the next recurse
	void dfs(vector<int>& stack, vector<vector<int> >& result, vector<int>& candidates, int target)
	{
		//if(target < 0) return;

		if(target == 0)
		{
			result.push_back(stack);
			return;
		}

		for(int i = 0; i < candidates.size(); ++i)
		{
			if(target < candidates[i]) return;

			stack.push_back(candidates[i]);
			dfs(stack, result, candidates, target - candidates[i]);
			stack.pop_back();
		}

	}
};

int main(int argc, char const *argv[])
{
	Solution sol;
	vector<vector<int> > result;
	int target = 7;
	int arr[] = {2, 3, 4, 7};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.combinationSum(nums, target);
	//cout << result.size() << endl;

	for(int j = 0; j < result.size(); ++j)
	{
		for(int i = 0; i < result[j].size(); ++i)
		{
			cout << result[j][i] << " ";
		}
		cout << endl;
	}

	//cout << result[0].size() << endl;
	return 0;
}

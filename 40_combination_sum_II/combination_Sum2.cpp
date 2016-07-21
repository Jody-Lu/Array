#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
	{
		vector<vector<int> > result;

		sort(candidates.begin(), candidates.end());

		vector<int> stack;
		//vector<int>::iterator first = candidates.begin();

		recurse(stack, result, candidates, target, 0);


		for(int i = 0; i < result.size(); i++)
		{
			sort(result[i].begin(), result[i].end());
		}

		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());

		return result;
	}
private:
	void recurse(vector<int>& stack, vector<vector<int> >& result, vector<int>& candidates, int target, int start)
	{
		if(start >= candidates.size() && target > 0) return;

		int previous = -1;
		//int i = start;

		if(target == 0)
		{
			result.push_back(stack);
			return;
		}

		//if(i > candidates.size()) return;

		for(int i = start; i < candidates.size(); ++i)
		{
			if(candidates[i] == previous) continue;

			if(target < candidates[i]) return;

			previous = candidates[i];

			//cout << i << " " << previous << endl;

			stack.push_back(candidates[i]);
			recurse(stack, result, candidates, target - candidates[i], start + 1);
			stack.pop_back();
		}

	}
};



int main(int argc, char const *argv[])
{
	Solution sol;
	vector<vector<int> > result;
	int target = 4;
	int arr[] = {1, 2};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.combinationSum2(nums, target);
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
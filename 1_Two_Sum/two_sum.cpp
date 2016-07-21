#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> mapping;
		vector<int> result;
		for(int i = 0; i < nums.size(); ++i)
		{
			mapping[nums[i]] = i; // nums' element : key
		}
		for(int i = 0; i < nums.size(); ++i)
		{
			const int gap = target - nums[i];
			if(mapping.find(gap) != mapping.end() && mapping[gap] > i)
			{
				result.push_back(i+1);
				result.push_back(mapping[gap] + 1);
				break;
			}
		}
		return result;

	}
};

int main()
{
	Solution sol;
	int target = 9;
	int arr[] = {2, 7, 11, 15};
	vector<int> nums(arr, arr+4);
	vector<int> result = sol.twoSum(nums, target);

	for(vector<int>::iterator it = result.begin(); it != result.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;


}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int result = 0;
		map<int, int> mapping;
		for(int i = 0; i < nums.size(); ++i)
		{
			mapping[nums[i]] = 0;
		}

		for(int i = 0; i < nums.size(); ++i)
		{
			mapping[nums[i]]++;
		}

		for(map<int, int>::iterator it = mapping.begin(); it != mapping.end(); ++it)
		{
			if(it -> second == 1)
				result = it -> first;
			cout << it -> first << " " << it -> second << endl;
		}
		return result;
	}
};

int main()
{
	Solution sol;
	int arr[] = {0, 1, 2, 0, 2};
	vector<int> nums(arr, arr+5);
	cout << sol.singleNumber(nums) << endl;
}

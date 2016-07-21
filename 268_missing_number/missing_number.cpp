#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{

		int res = nums.size();
		for(int i = 0; i < nums.size(); ++i)
		{
			res = res ^ i ^ nums[i];
			cout << res << " ";
		}
		cout << endl;
		return res;

		/* version 2 -- sum
		int result;
		int nums_length = nums.size();
		int sum = nums_length * (nums_length + 1) / 2;

		result = sum - accumulate(nums.begin(), nums.end(), 0);

		return result;
		*/

	}

};

int main(int argc, char const *argv[])
{
	Solution sol;
	int result;
	int arr[] = {0, 1, 3, 4};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.missingNumber(nums);
	cout << result << endl;

	return 0;
}
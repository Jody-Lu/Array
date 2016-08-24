#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int result = INT_MIN, f = 0;
		for(int i = 0; i < nums.size(); ++i)
		{
			f = max(f + nums[i], nums[i]); // either concatenate or choosing nums[i] 
            result = max(result, f); 
		}

		return result;
	}
};

int main()
{
	Solution sol;
	int result;
	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.maxSubArray(nums);
	//cout << result << endl;;
}

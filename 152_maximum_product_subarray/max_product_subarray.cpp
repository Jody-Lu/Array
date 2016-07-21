#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		int maxProduct = nums[0];
		int max_tmp = nums[0];
		int min_tmp = nums[0];

		for(int i = 1; i < nums.size(); ++i)
		{
			// 因為不知道當前的最大值或最小值在下一輪會不會變成最小值或最大值，
			// 因此都要存起來
			int a = nums[i] * max_tmp;
			int b = nums[i] * min_tmp;

			max_tmp = max(max(a, b), nums[i]);
			min_tmp = min(min(a, b), nums[i]);
			maxProduct = max(maxProduct, max_tmp);
		}

		return maxProduct;
	}

};

int main()
{
	Solution sol;
	int result;
	int arr[] = {7, -2, -4};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.maxProduct(nums);
	cout << result << endl;
}
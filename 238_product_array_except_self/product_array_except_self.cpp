#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		const int n = nums.size();
		vector<int> sub_result_1(n);
		vector<int> sub_result_2(n);
		vector<int> result(n);
		sub_result_1[0] = 1;
		sub_result_2[n - 1] = 1;

		for(int i = 1; i < n; ++i)
		{
			sub_result_1[i] = nums[i - 1] * sub_result_1[i - 1];
			sub_result_2[n - i - 1] = nums[n - i] * sub_result_2[n - i];
		}

		for(int i = 0; i < n; ++i)
		{
			result[i] = sub_result_1[i] * sub_result_2[i];
		}

		return result;
	}
};

int main()
{

	Solution sol;
	vector<int> result;
	int arr[] = {1, 2, 3, 4};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));

	result = sol.productExceptSelf(nums);

	for(vector<int>::iterator it = result.begin();
		it != result.end();
		it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
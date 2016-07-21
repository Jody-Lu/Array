#include <iostream>
#include <vector>

using namespace std;

//

class Solution
{
public:
	// binary serach
	int findMin(vector<int>& nums)
	{
		if(nums[0] < nums[nums.size() - 1]) return nums[0];
		int low = 0;
		int up = nums.size() - 1;
		int mid;

		while(low < up)
		{
			mid = (low + up) / 2;
			if(nums[mid] > nums[up])
			{
				low = mid + 1;
			}
			else
			{
				up = mid;
			}
		}
		//cout << low << endl;
		return nums[low];
	}
	/*
	int findMin(vector<int>& nums)
	{
		if(nums.size() == 1) return nums[0];
		int pivot = 1;

		while(pivot < nums.size())
		{
			if(nums[pivot - 1] < nums[pivot]) ++pivot;
			else
			{
				return min(nums[pivot], nums[0]);
			}
		}
		return nums[0];
		//cout << pivot << endl;

	}
	*/
};

int main()
{
	Solution sol;
	int result;
	int arr[] = {10, 1, 10, 10, 10};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.findMin(nums);
	cout << result << endl;
}

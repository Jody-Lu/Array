#include <iostream>
#include <vector>

using namespace std;



class Solution
{
public:

	int findMin(vector<int>& nums)
	{
		if(nums.size() == 1) return nums[0];
		int pivot = 1;

		while(pivot < nums.size())
		{
			if(nums[pivot - 1] <= nums[pivot]) ++pivot;
			else
			{
				return min(nums[pivot], nums[0]);
			}
		}
		return nums[0];

	}
};
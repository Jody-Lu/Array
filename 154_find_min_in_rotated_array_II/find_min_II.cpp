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

class Solution {
public:
    int findMin(vector<int>& nums) {
        int rp = 1;
        int n = nums.size();
        if(n == 1) return nums[0];

        while(rp < n && nums[rp] >= nums[rp - 1]) rp++;
        if(rp == n) return nums[0];
        else return nums[rp];
    }
};

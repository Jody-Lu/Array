#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		int reach = 1;
		for(int i = 0; i < reach && reach < nums.size(); ++i)
		{
			reach = max(reach, i + 1 + nums[i]);
		}

		return reach >= nums.size();
	}
};

int main()
{
	Solution sol;
	int result;
	int arr[] = {2, 0, 0};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	cout << sol.canJump(nums) << endl;

}
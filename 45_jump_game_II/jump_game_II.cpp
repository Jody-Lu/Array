#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int jump(vector<int>& nums)
	{
		//greedy: 每次都盡可能jump最多index
		if(nums.size() == 1) return 0;
		if(nums[0] >= nums.size() - 1) return 1;

		int reach = 1;
		int index = 0;
		int range;
		int jump_time = 1;


		while(reach < nums.size())
		{
			jump_time++;
			range = index + nums[index];
			for(int i = index; i <= range; ++i)
			{
				if(reach > i + 1 + nums[i]) continue;

				reach = i + 1 + nums[i];
				index = i;
			}

		}

		return jump_time;
	}
};

int main()
{
	Solution sol;
	int result;
	int arr[] = {1, 1, 1, 1};//{7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.jump(nums);
	cout << "result: " << result << endl;

}
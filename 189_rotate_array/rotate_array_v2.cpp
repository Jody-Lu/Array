#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void rotate(vector<int>& nums, int k)
	{
		vector<int> temp = nums;
		int nums_length = nums.size();
		
		if(nums_length == 1) return;

		while(k >= nums_length)
		{
			k = k - nums_length;
		}

		for(int i = 0; i < k; ++i)
		{
			nums[i] = temp[nums_length - k + i];
		}
		for(int i = 0; i < nums_length - k; ++i)
		{
			nums[k + i] = temp[i];
		}

	}

};

int main()
{
	Solution sol;
	int arr[] = {1,2,3,4,5,6,7,8};
	int k = 5;
	vector<int> nums(arr, arr+(sizeof(arr)/sizeof(*arr)));

	for(vector<int>::iterator it = nums.begin();
		it != nums.end();
		it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	sol.rotate(nums, k);

	for(vector<int>::iterator it = nums.begin();
		it != nums.end();
		it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
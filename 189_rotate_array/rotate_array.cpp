#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
	void rotate(vector<int>& nums, int k)
	{
		int nums_length = nums.size();

		if(nums_length == 1) return;

		if(k >= nums_length)
		{
			k = k - nums_length;
		}

		int shift_length = nums_length - 2 * k;
		int shift_start = nums_length - k;
		int shift_num = k;

		for(int i = 0; i < k; ++i)
		{
			swap(nums[i], nums[nums_length - k + i]);
		}

		if(k > nums_length / 2)
		{
			shift_num = k % (nums_length - k); //nums_length - k - 2; // number of elements to be shifted
			shift_length = nums_length - k - shift_num; // length of shift
			shift_start = nums_length - shift_num; // shift start element
		}

		if(k % (nums_length - k) == 0) return;

		for(int i = 0; i < shift_num; ++i)
		{
			for(int j = 0; j < shift_length; ++j)
			{
				swap(nums[shift_start - j + i], nums[shift_start - j + i - 1]);
			}
		}
	}
private:
	void swap(int& item_1, int& item_2)
	{
		int temp = item_2;
		item_2 = item_1;
		item_1 = temp;
	}
};


int main()
{
	Solution sol;
	//int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
	//int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54};
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
	int k = 82; // 29
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
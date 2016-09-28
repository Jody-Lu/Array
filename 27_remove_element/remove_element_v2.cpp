#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		vector<int> result;

		for(vector<int>::iterator it = nums.begin();
			it != nums.end();
			++it)
		{
			if(*it != val)
			{
				result.push_back(*it);
			}
		}

		nums = result;
		return nums.size();
	}
};

int main()
{
	Solution sol;
	int result;
	int val = 1;
	int arr[] = {1, 1, 2, 3, 1 ,5};
	vector<int> nums(arr, arr + (sizeof(arr)/sizeof(*arr)));
	result = sol.removeElement(nums, val);

	for(vector<int>::iterator it = nums.begin();
		it != nums.end();
		it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	cout << result << endl;

}

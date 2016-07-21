#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		vector<int>::iterator first = nums.begin();
		vector<int>::iterator last = nums.end();
		vector<int>::iterator result = first - 1;

		while(first != last)
		{
			if(!(*first == val))
			{
				*(++result) = *first;
			}
			++first;
		}

		nums.erase(++result, last);

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
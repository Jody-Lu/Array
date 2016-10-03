#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if(nums.size() == 0) return 0;

		vector<int>::iterator first = nums.begin();
		vector<int>::iterator last = nums.end();
		vector<int>::iterator result = first;

		while(++first != last)
		{
			if(!(*first == *result))
			{
				*(++result) = *first;
			}

		}
		nums.erase(++result, last);

		return nums.size();
	}

};

int main()
{
	int result;
	int arr[] = {1, 2, 2, 4 , 4, 5, 5, 6,  6, 8};
	Solution sol;
	vector<int> nums(arr, arr + (sizeof(arr)/sizeof(*arr)));
	result = sol.removeDuplicates(nums);

	for(vector<int>::iterator it = nums.begin();
		it != nums.end();
		it++)
	{
		cout << *it << " ";
	}

	cout << endl << result << endl;


}

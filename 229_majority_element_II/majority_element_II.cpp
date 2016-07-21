#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	vector<int> majorityElement(vector<int>& nums)
	{
		vector<int> result;
		map<int, int> count;
		for(int i = 0; i < nums.size(); ++i)
		{
			++count[nums[i]];
		}

		for(map<int, int>::iterator it = count.begin();
			it != count.end();
			++it)
		{
			if(it -> second > nums.size() / 3)
				result.push_back(it -> first);
		}

		return result;
	}

};

int main()
{
	Solution sol;
	vector<int> result;
	int arr[] = {2, 2};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.majorityElement(nums);
	for(vector<int>::iterator it = result.begin();
		it != result.end();
		++it)
	{
		cout << *it << " ";
	}
	cout << endl;

}
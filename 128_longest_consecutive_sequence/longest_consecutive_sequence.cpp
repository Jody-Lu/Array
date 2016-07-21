#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:

	int longestConsecutive(vector<int>& nums)
	{
		map<int, int> sets;
		for(vector<int>::iterator it = nums.begin();
			it != nums.end();
			++it)
		{
			sets[*it] = 1;
		}

		map<int, int>::iterator right = sets.begin();
		map<int, int>::iterator left = right;
		map<int, int>::iterator res = right;
		map<int, int>::iterator last = sets.end();

		while(++right != last)
		{
			if((right -> first) == (left -> first) + 1)
			{
				++(res -> second);
				++left;
			}
			else
			{
				left = right;
				res = right;
			}
		}

		int max_set = 0;

		for(map<int, int>::iterator it = sets.begin();
			it != sets.end();
			++it)
		{
			if(it -> second == 0) continue;
			max_set = max(max_set, int(it->second));
		}

		return max_set;
	}
	/*
	int longestConsecutive(vector<int>& nums)
	{
		map<int, int> sets;
		map<int, vector<int> > result;
		for(vector<int>::iterator it = nums.begin();
			it != nums.end();
			++it)
		{
			sets[*it] = *it;
		}

		map<int, int>::iterator right = sets.begin();
		map<int, int>::iterator left = right;
		map<int, int>::iterator last = sets.end();

		result[right -> second].push_back(right -> first);

		while(++right != last)
		{
			if((right -> first) == (left -> first) + 1)
			{
				right -> second = left -> second;
				result[right -> second].push_back(right -> first);
				++left;
			}
			else
			{
				result[right -> second].push_back(right -> first);
				left = right;
			}
		}

		int max_set = 0;

		for(map<int, vector<int> >::iterator it = result.begin();
			it != result.end();
			++it)
		{
			max_set = max(max_set, int((it->second).size()) );
		}

		return max_set;
	}
	*/

};

int main()
{
	Solution sol;
	int result;
	int arr[] = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	/*
	for(vector<int>::iterator it = nums.begin();
		it != nums.end();
		++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	*/

	result = sol.longestConsecutive(nums);
	cout << result << endl;
}
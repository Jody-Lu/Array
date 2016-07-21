#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		map<int, int> counts;

		for(vector<int>::iterator it = nums.begin();
			it != nums.end();
			++it)
		{
			++counts[*it];
			if(counts[*it] > 1) return true;
		}

		return false;
	}
};
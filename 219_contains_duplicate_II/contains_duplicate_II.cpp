#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		if(nums.size() <= 1) return false;
		map<int, vector<int> > counts;

		for(int i = 0; i < nums.size(); ++i)
		{
			counts[nums[i]].push_back(i);
		}

		for(map<int, vector<int> >::iterator it = counts.begin();
			it != counts.end();
			++it)
		{
			if((it -> second).size() > 1)
			{
				for(int i = 1; i < (it -> second).size(); ++i)
				{
					if((it -> second)[i] - (it -> second)[i - 1] <= k)
						return true;
				}
			}
		}

		return false;
	}
};

int main()
{
	Solution sol;
	int k = 1;
	bool result;
	int arr[] = {1, 0, 1, 1};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.containsNearbyDuplicate(nums, k);
	cout << result << endl;
}
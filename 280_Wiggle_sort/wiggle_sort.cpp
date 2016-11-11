#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void wiggleSort(vector<int>& nums)
	{
	    sort(nums.begin(), nums.end());
	    for(int i = 2; i < nums.size(); i += 2)
	    {
	    	swap(nums[i - 1], nums[i]);
	    }
	}

};

int main()
{
	Solution sol;
	int ini[] = {1, 6, 2, 5, 3, 4};
	vector<int> arr(ini, ini + 6);
	sol.wiggleSort(arr);

	for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << endl;
	}
}

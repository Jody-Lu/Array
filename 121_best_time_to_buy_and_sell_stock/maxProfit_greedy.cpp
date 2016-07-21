#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		if(prices.size() < 2) return 0;
		int profit = 0;
		int cur_min = prices[0];

		for(int i = 1; i < prices.size(); ++i)
		{
			profit = max(profit, prices[i] - cur_min);\
			cur_min = min(cur_min, prices[i]);
		}

		return profit;
	}
};

int main()
{
	Solution sol;
	int result;
	int arr[] = {1, 2, 4, 7, 8};//{9, 1, 4, 7, 3, 1, 0, 5, 8, 1, 6};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.maxProfit(nums);
	cout << result << endl;
	return 0;
}
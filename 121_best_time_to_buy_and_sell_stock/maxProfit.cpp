#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	// O(n^2)
	int maxProfit(vector<int>& prices)
	{
		const int days = prices.size();
		vector<vector<int> > result(days, vector<int>(days, 0));

		for(int i = 0; i < days; ++i)
		{
			result[i][i] = 0;
		}

		for(int i = 1; i < days; ++i)
		{
			result[0][i] = max((prices[i] - prices[0]), result[0][i - 1]);
		}

		for(int i = 1; i < days; ++i)
		{
			for(int j = i + 1; j < days; ++j)
			{
				if(i != j)
				{
					result[i][j] = max((prices[j] - prices[i]), max(result[i - 1][j], result[i][j - 1]));
					//result[i][j] = max((prices[j] - prices[i]), result[i - 1][j]);
				}
			}
		}


		for(int i = 0; i < days; ++i)
		{
			for(int j = 0; j < days; ++j)
			{
				cout << result[i][j] << " ";
			}
			cout << endl;
		}


		return result[days - 2][days - 1];
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
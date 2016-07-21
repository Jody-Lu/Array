#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	bool isHappy(int n)
	{
		int num = n;
		vector<int> nums;
		while(num != 1)
		{
			nums.push_back(num);
			int tmp = 0;
			while(num != 0)
			{
				int digit = num % 10;
				tmp += digit * digit;
				num /= 10;
			}
			if(find(nums.begin(), nums.end(), tmp) != nums.end())
			{
				return false;
			}
			num = tmp;
			//cout << num << endl;
		}
		return true;
	}
};

int main()
{
	Solution sol;
	cout << sol.isHappy(2) << endl;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> result;

		result.push_back(1);

		if(rowIndex == 0) return result;


		for(int i = 1; i <= rowIndex; ++i)
		{
			vector<int> tmp = result;
			for(int j = 1; j < tmp.size(); ++j)
			{
				result[j] = tmp[j] + tmp[j - 1];
			}
			result.push_back(1);
		}
		return result;

	}
};

int main()
{
	int rowIndex = 1;
	vector<int> result;
	Solution sol;
	result = sol.getRow(rowIndex);

	for(vector<int>::iterator it = result.begin();
		it != result.end();
		++it)
	{
		cout << *it << " ";
	}

	cout << endl;
	return 0;
}
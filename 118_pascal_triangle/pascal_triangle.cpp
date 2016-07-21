#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int> > generate(int numRows)
	{
		vector<vector<int> > result;
		vector<int> row;

		if(numRows == 0) return result;

		row.push_back(1);
		result.push_back(row);

		if(numRows == 1) return result;

		for(int i = 2; i <= numRows; ++i)
		{
			vector<int> tmp = row;
			for(int j = 1; j < tmp.size(); ++j)
			{
				row[j] = tmp[j] + tmp[j - 1];
			}
			row.push_back(1);
			result.push_back(row);
		}
		return result;
	}
};

int main()
{
	int numRows = 10;
	Solution sol;
	vector<vector<int> > result;
	result = sol.generate(numRows);
	for(vector<vector<int> >::iterator it = result.begin();
		it != result.end();
		++it)
	{
		for(vector<int>::iterator itt = (*it).begin();
			itt != (*it).end();
			itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;
	}

	return 0;
}
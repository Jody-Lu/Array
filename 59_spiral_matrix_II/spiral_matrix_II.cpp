#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int> > generateMatrix(int n)
	{
		vector<vector<int> > result(n, vector<int>(n));
		vector<int> array(n*n);
		int beginX = 0, endX = n - 1;
		int beginY = 0, endY = n - 1;
		int count = 0;
		// create the array
		for(int i = 0; i < array.size(); ++i)
		{
			array[i] = (i + 1);
		}

		while(true)
		{
			// From left to right
			for(int i = beginX; i <= endX; ++i)
			{
				result[beginY][i] = array[count];
				count++;
			}
			if(++beginY > endY) break;
			// From top to bottom
			for(int j = beginY; j <= endY; ++j)
			{
				result[j][endX] = array[count];
				count++;
			}
			if(--endX < beginX) break;
			// From right to left
			for(int i = endX; i >= beginX; --i)
			{
				result[endY][i] = array[count];
				count++;
			}
			if(--endY < beginY) break;
			// From bottom to top
			for(int j = endY; j >= beginY; --j)
			{
				result[j][beginX] = array[count];
				count++;
			}
			if(++beginX > endX) break;
		}
		return result;
	}
};

int main()
{
	int  n = 3;
	Solution sol;
	vector<vector<int> > result;
	result = sol.generateMatrix(n);

	for(vector<vector<int> >::iterator it = result.begin();
		it != result.end();
		it++)
	{
		for(vector<int>::iterator itt = (*it).begin();
			itt != (*it).end();
			itt++)
		{
			cout << *(itt) << " ";
		}
		cout << endl;
	}

}
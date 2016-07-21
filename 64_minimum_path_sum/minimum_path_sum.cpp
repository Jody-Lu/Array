#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int minPathSum(vector<vector<int> >& grid)
	{
		int grid_row = grid.size();
		int grid_col = grid[0].size();


		vector<vector<int> > result(grid_row, vector<int>(grid_col, 0));

		result[0][0] = grid[0][0];

		for(int i = 1; i < grid_col; ++i)
		{
			result[0][i] = result[0][i - 1] + grid[0][i];

		}


		for(int i = 1; i < grid_row; ++i)
		{
			result[i][0] = result[i - 1][0] + grid[i][0];
		}



		for(int i = 1; i < grid_row; ++i)
		{
			for(int j = 1; j < grid_col; ++j)
			{
				result[i][j] = min(result[i - 1][j], result[i][j - 1]) + grid[i][j];
			}
		}


		return result[grid_row - 1][grid_col - 1];

	}

};

int main()
{
	Solution sol;
	int result;

	vector<vector<int> > matrix;
	int arr_1[] = {1, 2, 3};
	vector<int> v1(arr_1, arr_1 + 3);
	matrix.push_back(v1);
	int arr_2[] = {4, 5, 6};
	vector<int> v2(arr_2, arr_2 + 3);
	matrix.push_back(v2);
	//int arr_3[] = {7, 8, 9};
	//vector<int> v3(arr_3, arr_3 + 3);
	//matrix.push_back(v3);

	result = sol.minPathSum(matrix);
	cout << result << endl;


}
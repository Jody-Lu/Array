#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int minPathSum(vector<vector<int> >& grid)
	{
		const int m = grid.size();
		const int n = grid[0].size();

		this -> f = vector<vector<int> >(m, vector<int>(n, -1));
		return dfs(grid, m - 1, n - 1);
	}
private:
	vector<vector<int> > f;
	int dfs(const vector<vector<int> >& grid, int x, int y)
	{
		if(x < 0 || y < 0) return INT_MAX;

		if(x == 0 && y == 0) return grid[0][0];

		return min(getOrUpdate(grid, x - 1, y), getOrUpdate(grid, x, y - 1)) + grid[x][y];
	}
	int getOrUpdate(const vector<vector<int> >& grid, int x, int y)
	{
		if(x < 0 || y < 0) return INT_MAX;
		if(f[x][y] >= 0) return f[x][y];
		else return f[x][y] = dfs(grid, x, y);
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
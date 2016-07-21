#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int> >& matrix)
	{
		vector<vector<int> > temp = matrix;
		int column = 0;
		int dimension = matrix.size();

		for(int row = 0; row < dimension; ++row) //matrix[row][column]
		{
			for(int column = 0; column < dimension; ++column)
			{
				matrix[column][dimension - row - 1] = temp[row][column];
			}
		}

	}

};

int main()
{
	Solution sol;

	vector<vector<int> > matrix;
	int arr_1[] = {1, 2, 3};
	vector<int> v1(arr_1, arr_1 + 3);
	matrix.push_back(v1);
	int arr_2[] = {4, 5, 6};
	vector<int> v2(arr_2, arr_2 + 3);
	matrix.push_back(v2);
	int arr_3[] = {7, 8, 9};
	vector<int> v3(arr_3, arr_3 + 3);
	matrix.push_back(v3);

	sol.rotate(matrix);

	cout << matrix[0][1] << endl;

	for(int i = 0; i < matrix.size(); ++i)
	{
		for(int j = 0; j < matrix.size(); ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}
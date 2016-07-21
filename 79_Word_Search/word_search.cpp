#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public: 
	bool exist(vector<vector<char> >& board, string word){ // board: the 2-D grid, word: the input string
		const int m = board.size(); 	// board's length of column (vertical)
		const int n = board[0].size();  // board's length of row (horizon)
		//vector<vector<bool> > visited(m, vector<bool>(n, false)); // initialize all grid unvisited
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if (dfs(board, word, i, j))
				{
					return true;
				}
			}
		}
		return false;
	}
private:
	static bool dfs(vector<vector<char> >& board, string word, int x, int y)
	{	// x: vertical, y: horizon
		if(word.size() == 0)
		{
			return true;
		}

		if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
		{
			return false;
		}

		if(word[0] == board[x][y])
		{
			char c = word[0];
			board[x][y] = '\0';
			if(dfs(board, word.substr(1), x-1, y) || // up
				dfs(board, word.substr(1), x+1, y)|| // down
				dfs(board, word.substr(1), x, y-1)|| // left
				dfs(board, word.substr(1), x, y+1))
			{
				return true;
			}
			board[x][y] = c;
		}
		return false;

	}
};

int main()
{
	Solution sol;
	string word = "ABCCED";
	vector<vector<char> > board;
	char arr1[] =  {'A', 'B', 'C', 'E'};
	char arr2[] =  {'S', 'F', 'C', 'S'};
	char arr3[] =  {'A', 'D', 'E', 'E'};

	vector<char> str1(arr1, arr1+4);
	board.push_back(str1);
	vector<char> str2(arr2, arr2+4);
	board.push_back(str2);
	vector<char> str3(arr3, arr3+4);
	board.push_back(str3);


	cout << sol.exist(board, word) << endl;
	cout << word.substr(1) << endl;

}


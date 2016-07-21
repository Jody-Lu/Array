#include <iostream>
#include <vector>
#include <map>

using namespace std;

// can use hash table for enhancing checking step
class Sudoku
{
public:
	// constructor
	Sudoku(vector<vector<char> > board): unsolved_board(board), board_width(board.size()), grid_size(board.size()/3)
	{
		for(int i = 0; i < board.size(); ++i)
		{
			count.push_back(vector<int>());
			for(int j = 0; j < board.size(); ++j)
			{
				count[i].push_back(9);
			}
		}
	}

	void solveSudoku()
	{
		solve(0);
	}
	/*
	void solveSudoku(vector<vector<char> >& board)
	{
		solve(0, board);
	}
	*/
	void print_board()
	{
		for(int i = 0; i < board_width; ++i)
		{
			for(int j = 0; j < board_width; ++j)
			{
				//cout << unsolved_board[i][j] << " ";
				cout << count[i][j] << " ";
			}
			cout << endl;
		}
		cout << "board_width: " << board_width << endl;
	}
	void empty_count()
	{
		for(int j = 0; j < board_width; ++j)
		{
			for(int i = 0; i < board_width; ++i)
			{
				if(unsolved_board[j][i] != '.')
					count[j][i] = -1;
			}
		}
	}
private:
	// private member function
	// check wheather a number at (x, y) is a valid number in sudoku
	bool check(int x, int y)
	{
		for(int i = 0; i < board_width; ++i)
		{
			// check row and column for duplicated term
			if((i != y && unsolved_board[x][i] == unsolved_board[x][y])
				||(x != i && unsolved_board[i][y] == unsolved_board[x][y]))
			{
				return false;
			}
        }
		// check 3x3 grid
		for(int i = 0; i < board_width/grid_size; ++i)
		{
			for(int j = 0; j < board_width/3; ++j)
			{
				if(unsolved_board[(x/grid_size)*grid_size + i][(y/grid_size)*grid_size + j] == unsolved_board[x][y]
					&& x != (x/grid_size)*grid_size + i
					&& y != (y/grid_size)*grid_size + j
				) return false;
			}
		}

		
		return true;
	}
	// solve the Sudoku
	bool solve(int cur)
	{
		// when the solving process done
		if(cur == board_width * board_width) return true;

		//determine the row/col to be solving
		int i = cur / board_width; // row
		int j = cur % board_width; // column

		// if the (row, column) has been a number, next
		if(unsolved_board[i][j] != '.') return solve(cur + 1);

		// for '.', check from 1 to 9
		// 'check': whether it's valid
		// 'solve': whether it's valid in the next step
		for(int k = 1; k <= board_width; ++k)
		{
			unsolved_board[i][j] = k + '0';
			if(check(i, j) && solve(cur + 1))
				return true;
			unsolved_board[i][j] = '.';
		}
		return false;

	}
	// private member
	vector<vector<char> > unsolved_board;
	vector<vector<int> > count;
	int board_width;
	int grid_size;
};





vector<char> make_line(string line)
{
	vector<char> res;
	for(int i = 0; i < line.size(); ++i)
	{
		res.push_back(line[i]);
	}
	return res;
}

int main()
{
	vector<vector<char> > board;
	string lines[9] = {"8.........", "..36.....", ".7..9.2..", ".5...7...", "....457..", "...1...3.", "..1....68", "..85...1.", ".9....4.."};

	for(int i = 0; i < 9; ++i)
	{
		board.push_back(make_line(lines[i]));
	}
	Sudoku sudoku(board);
	//sudoku.solveSudoku();
	sudoku.empty_count();
	sudoku.print_board();

	/*
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}

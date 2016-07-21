#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> >& board)
    {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == '.') continue;
                else if(!check(i, j, board))
                {
                    return false;
                }
            }
        }

        return true;
    }
private:
    bool check(int x, int y, vector<vector<char> >& board)
    {
        for(int i = 0; i < board.size(); ++i)
        {
            // check row and column for duplicated term
            if((i != y && board[x][i] == board[x][y])
                ||(x != i && board[i][y] == board[x][y]))
            {
                return false;
            }
        }
        for(int i = 0; i < board.size()/3; ++i)
        {
            for(int j = 0; j < board.size()/3; ++j)
            {
                if(board[(x/3)*3 + i][(y/3)*3 + j] == board[x][y]
                    && x != (x/3)*3 + i
                    && y != (y/3)*3 + j)
                return false;
            }
        }
        
        return true;
    }
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
    string lines[9] = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
    for(int i = 0; i < 9; ++i)
    {
        board.push_back(make_line(lines[i]));
    }

    Solution sol;
    cout << sol.isValidSudoku(board) << endl;
}

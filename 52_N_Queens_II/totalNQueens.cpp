#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        int totalNQueens(int n) {
            int res = 0;
            vector<string> board(n, string(n, '.'));
            solveNQUtil(res, board, 0);
            return res;
        }
    private:
        bool isSafe(vector<string> &board, int row, int col) {
            int i, j;
            int N = board.size();

            /* Check this row on left side. */
            for (i = 0; i < col; i++)
                if (board[row][i] == 'Q')
                    return false;

            /* Check upper diagonal on left side. */
            for (i=row, j=col; i>=0 && j>=0; i--, j--)
                if (board[i][j] == 'Q')
                    return false;

            /* Check lower diagonal on left side */
            for (i=row, j=col; j>=0 && i < N; i++, j--)
                if (board[i][j] == 'Q')
                    return false;

            return true;
        }

        void solveNQUtil(int &res, vector<string> board, int col) {
            int N = board.size();
            if(col >= N) {
                res++;
                return;
            }

            /* Consider this column and try placing
            this queen in all rows one by one */
            for(int i = 0; i < N; i++) {
                /* Check if queen can be placed on
                board[i][col] */
                if(isSafe(board, i, col)) {
                    /* Place this queen in board[i][col] */
                    board[i][col] = 'Q';

                    /* recur to place rest of the queens */
                    solveNQUtil(res, board, col + 1);

                    board[i][col] = '.'; // BACKTRACK
                }
            }
        }
};

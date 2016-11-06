#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void solve(vector<vector<char> >& board) {
            int m = board.size();
            int n = board[0].size();

            for(int j = 0; j < n; j++) {
                if(board[0][j] == 'O') {
                    bfsBoundary(board, 0, j);
                }

                if(board[m - 1][j] == 'O') {
                    bfsBoundary(board, m - 1, j);

                }
            }

            for(int i = 0; i < m; i++) {
                if(board[i][0] == 'O' ) {
                    bfsBoundary(board, i, 0);
                }

                if(board[i][n - 1] == 'O') {
                    bfsBoundary(board, i, n - 1);
                }
            }

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(board[i][j] == 'B') {
                        board[i][j] = 'O';
                    }
                    else if(board[i][j] == 'O') {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    private:
        void bfsBoundary(vector<vector<char> >& board, int w, int l) {
            int m = board.size();
            int n = board[0].size();
            int dw[4] = {1, -1, 0, 0};
            int dl[4] = {0, 0, 1, -1};
                
            board[w][l] = 'B';

            for(int i = 0; i < 4; i++) {
                int nextW = w + dw[i];
                int nextL = l + dl[i];
                if(nextW >= 0 && nextW < m &&
                   nextL >= 0 && nextL < n &&
                   board[nextW][nextL] == 'O') {
                    bfsBoundary(board, nextW, nextL);
                }
            }

        }
};

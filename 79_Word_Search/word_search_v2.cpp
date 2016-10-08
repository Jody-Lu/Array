class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0])
                    if(dfs(board, word, i, j, 0))
                        return true;
        return false;
    }
private:
    bool dfs(vector<vector<char> >& board, string word, int x, int y, int k) {
        if(k >= word.size())
            return true;

        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;

        if(board[x][y] == word[k]) {
            char tmp = board[x][y];
            board[x][y] = '\0';
            if(dfs(board, word, x - 1, y, k + 1) ||
               dfs(board, word, x + 1, y, k + 1) ||
               dfs(board, word, x, y - 1, k + 1) ||
               dfs(board, word, x, y + 1, k + 1))
               return true;
            board[x][y] = tmp;
        }
        return false;
    }
};
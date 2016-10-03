class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end());
        for(int i = 0; i < words.size(); i++) {
            if(i and words[i] == words[i - 1]) continue;
            if(findWordsUtil(board, words[i]))
                res.push_back(words[i]);
        }
        return res;
    }

private:
    bool findWordsUtil(vector<vector<char> > board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == word.front())
                    if(dfs(board, word, i , j, 0))
                        return true;
        return false;
    }
    bool dfs(vector<vector<char> > &board, string word, int x, int y, int k) {
        if(k >= word.size()) return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return false;

        if(board[x][y] == word[k]) {
            char tmp = board[x][y];
            board[x][y] = '\0';
            if(dfs(board, word, x - 1, y, k + 1) || 
               dfs(board, word, x + 1, y, k + 1) ||
               dfs(board, word, x, y + 1, k + 1) ||
               dfs(board, word, x, y - 1, k + 1))
               return true;
            board[x][y] = tmp;
        }
        return false;
    }
};
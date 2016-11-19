class Solution {
    class Trie {
        public:
            Trie *next[26];
            bool isLeaf;
            int idx;
            Trie(): isLeaf(false), idx(0) {
                memset(next, NULL, sizeof(next));
            }
    };

public:
    void insertWords(Trie *root, vector<string>& words, int& idx) {
        int pos = 0, len = words[idx].size();
        Trie* tNode = root;

        for(char c : words[idx]) {
            if(tNode->next[c - 'a'] == NULL) {
                tNode->next[c - 'a'] = new Trie();
            }
            tNode = tNode->next[c - 'a'];
        }

        tNode -> isLeaf = true;
        tNode -> idx = idx;
    }

    Trie* buildTrie(vector<string> &words) {
        Trie *root = new Trie();
        int i;
        for(i = 0; i < words.size(); i++) {
            insertWords(root, words, i);
        }
        return root;
    }

    void checkWords(vector<vector<char> >& board, int row, int col,
                    Trie *root, vector<string>& res, vector<string>& words)
    {
        char tmp;

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return;
        }

        if(board[row][col] == 'X') {
            return;

        } // visited before

        if(root->next[board[row][col] - 'a'] == NULL) {
            return;
        } // no string with such prefix
        else {
            tmp = board[row][col];
            if(root->next[tmp - 'a']->isLeaf)
            {
                res.push_back(words[root->next[tmp - 'a']->idx]);
                root->next[tmp - 'a']->isLeaf = false; // set to false to indicate that we found it already
            }

            board[row][col] = 'X'; //mark the current position as visited

            checkWords(board, row - 1, col, root->next[tmp - 'a'], res, words);
            checkWords(board, row + 1, col, root->next[tmp - 'a'], res, words);
            checkWords(board, row, col - 1, root->next[tmp - 'a'], res, words);
            checkWords(board, row, col + 1, root->next[tmp - 'a'], res, words);

            board[row][col] = tmp; // recover the current position (Backtracking)
        }
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string> &words) {
        vector<string> res;
        int row = board.size();
        if(row == 0) return res;
        int col = board[0].size();
        if(col == 0) return res;
        int wordCount = words.size();
        if(wordCount == 0) return res;

        Trie *root = buildTrie(words);
        int i, j;
        for(i = 0; i < row; i++) {
            for(j = 0; j < col && wordCount > res.size(); j++) {
                checkWords(board, i, j, root, res, words);
            }
        }
        return res;
    }

};

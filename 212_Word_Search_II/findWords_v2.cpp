#include <iostream>
#include <vector>

using namespace std;

class Solution {
    class Trie {
        public:
            Trie *next[26];
            bool isLeaf;
            int idx;
            Trie() {
                this -> isLeaf = false;
                this -> idx = 0;
                fill_n(this -> next, 26, nullptr);
            }
    };
public:
    void insertWords(Trie *root, vector<string> &words, int idx) {
        int pos = 0, len = words[idx].size();
        while(pos < len) {
            if(root->next[words[idx][pos] - 'a'] == nullptr)
                root -> next[words[idx][pos] - 'a'] = new Trie();
            root = root -> next[words[idx][pos++] - 'a'];
        }
        root -> isLeaf = true;
        root -> idx = idx;
    }

    Trie* buildTrie(vector<string> &words) {
        Trie *root = new Trie();
        int i;
        for(i = 0; i < words.size(); i++)
            insertWords(root, words, i);
        return root;
    }

    void checkWords(vector<vector<char> >& board, int i, int j,
                   int row, int col, Trie *root, vector<string> &res, vector<string> &words)
    {
        char tmp;
        if(board[i][j] == 'X') return; // visited before
        if(root->next[board[i][j] - 'a'] == nullptr) return; // no string with such prefix
        else {
            tmp = board[i][j];
            if(root->next[tmp - 'a']->isLeaf) { // if it's a leaf
                res.push_back(words[root->next[tmp - 'a']->idx]);
                root->next[tmp - 'a']->isLeaf = false; // set to false to indicate that we found it already
            }
            board[i][j] = 'X'; //mark the current position as visited
            
            if(i > 0) checkWords(board, i-1, j, row, col, root->next[tmp - 'a'], res, words);
            if((i+1) < row) checkWords(board, i+1, j, row, col,  root->next[tmp-'a'], res, words);
            if(j > 0) checkWords(board, i, j-1,  row, col, root->next[tmp-'a'], res, words);
            if((j+1) < col) checkWords(board, i, j+1,  row, col, root->next[tmp-'a'], res, words);

            board[i][j] = tmp; // recover the current position (Backtracking)
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
                checkWords(board, i, j, row, col, root, res, words);
            }
        }
        return res;
    }
        
};

int main() {
    return 0;
}

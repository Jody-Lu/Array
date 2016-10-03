#include <iostream>
#include <vector>
#include <string>
#define ALPHABET_SIZE (26)

using namespace std;

class TrieNode {
    public:
        TrieNode* next[26];
        bool isLeaf;
        TrieNode(bool b=false) {
            memset(next, 0, sizeof(next));
            isLeaf = b;
        }
};

class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(string s) {
            TrieNode *p = root;
            for(int i = 0; i < s.size(); i ++) {
                if(p->next[s[i] - 'a'] == NULL)
                    p -> next[s[i] - 'a'] = new TrieNode();
                p = p -> next[s[i] - 'a'];
            }
            p -> isLeaf = true;
        }

        int countNexts(TrieNode *p, int *index) {
            int count = 0;
            for(int i = 0; i < ALPHABET_SIZE; i++) {
                if(p->next[i] != NULL) {
                    count++;
                    *index = i;
                }
            }
            return count;
        }

        string walkTrie() {
            TrieNode* p = root;
            int index;
            string prefix;
            while((countNexts(p, &index) == 1) &&
                  !(p -> isLeaf)) 
            {
                p = p -> next[index];
                prefix.push_back('a' + index);
            }

            return prefix;
        }



    private:
        TrieNode *root;
};


class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            Trie trie;
            for(int i = 0; i < strs.size(); i++) {
                trie.insert(strs[i]);
            }
            return trie.walkTrie();
        }
};

int main() {
    Solution sol;
    vector
}

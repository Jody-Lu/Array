#include <iostream>

using namespace std;

class TrieNode {
    public:
        bool isWord;
        TrieNode* next[26];
        TrieNode(bool b = false): isWord(b) {
            memset(next, NULL, sizeof(next));
        }
};

class WordDictionary {
    public:
        WordDictionary() {
            root = new TrieNode();
        }

        // Adds a word into the data structure.
        void addWord(string word) {
            TrieNode* tNode = root;
            for(char c : word) {
                if(tNode->next[c - 'a'] == NULL) {
                    tNode->next[c - 'a'] = new TrieNode();
                }
                tNode = tNode->next[c - 'a'];
            }

            tNode->isWord = true;
        }

        bool search(string word) {
            return query(word, root);
        }

    private:
        TrieNode* root;

        bool query(string word, TrieNode* node) {
            TrieNode* tNode = node;
            for(int i = 0; i < word.size(); i++) {
                if(tNode && word[i] != '.') {
                    tNode = tNode->next[word[i] - 'a'];
                }
                else if(tNode && word[i] == '.') {
                    TrieNode* tmp = tNode;
                    for(int j = 0; j < 26; j++) {
                        tNode = tmp->next[j];
                        if(query(word.substr(i + 1), tNode)) {
                            return true;
                        }
                    }
                }
                else {
                    break;
                }
            }

            return tNode && tNode->isWord;
        }
};

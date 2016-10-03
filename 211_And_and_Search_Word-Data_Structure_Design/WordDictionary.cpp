#include <iostream>
#include <string>

using namespace std;

class WordDictionary {
	public:
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
                    for(int i = 0; i < s.size(); i++) {
                        if(p -> next[s[i] - 'a'] == NULL)
                            p -> next[s[i] - 'a'] = new TrieNode();
                        p = p -> next[s[i] - 'a'];
                    }
                    p -> isLeaf = true;
                }
            private:
                TrieNode *root;
        };

        WordDictionary() {
            this -> myTrie = new Trie();
        }
    	
    	// Adds a word into the data structure.
    	void addWord(string word) {
    	    myTrie -> insert(word);    
    	}

    	// Returns if the word is in the data structure. A word could
    	// contain the dot character '.' to represent any one letter.
    	bool search(string word) {
    	    // How to handle '.' problem.
            return true;    
    	}
    private:
        TrieNode* find(string key) {
            TrieNode* p = root;
            for(int i = 0; i < key.size() && p != NULL; i++)
                if(key[i] != '.')
                    p = p -> next[key[i] - 'a'];
                else

            return p;
        }
        Trie *myTrie;
};


int main() {
    WordDictionary w;
    w.addWord("word");
}

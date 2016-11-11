#include <iostream>
#include <vector>
#define ALPHABET_SIZE 26


using namespace std;


class TrieNode {
	public:
    	// Initialize your data structure here.
    	TrieNode *next[ALPHABET_SIZE];
        bool isWord;
        TrieNode(bool b=false) {
            // void * memset ( void * ptr, int value, size_t num );
            // Sets the first num bytes of the block of memory pointed by ptr to the specified value
            memset(next, 0, sizeof(next));
            isWord = b;
    	}
};

class Trie {
	public:
    	Trie() {
        	root = new TrieNode();
    	}

    	// Inserts a word into the trie.
        void insert(string s) {
            TrieNode* p = root;
            for(int i = 0; i < s.size(); i++) {
                if(p -> next[s[i] - 'a'] == NULL)
                    p -> next[s[i] - 'a'] = new TrieNode();
                p = p -> next[s[i] - 'a'];
            }
            p -> isWord = true;
        }

        // Delete a key from a Trie
        void deleteKey(string key) {
            if(!key.empty()) {
                deleteHelper(this->root, key, 0, key.size());
            }
        }

        // Returns if the word is in the trie.
    	bool search(string key) {
            TrieNode* p = find(key);
            return p != NULL && p -> isWord;
    	}

    	// Returns if there is any word in the trie
    	// that starts with the given prefix.
    	bool startsWith(string prefix) {
            return find(prefix) != NULL;
    	}

        bool isLeafNode(TrieNode* p) {
            return p->isWord; 
        }

        // identify whether the node has next
        bool isFreeNode(TrieNode* p) {
            int i;
            for(i = 0; i < ALPHABET_SIZE; i++) {
                if(p -> next[i])
                    return false;
            }
            return true;
        }

	private:
        TrieNode* find(string key) {
            TrieNode* p = root;
            for(int i = 0; i < key.size() && p != NULL; i++)
                p = p -> next[key[i] - 'a'];
            return p;
        }
        
        // The helper function to delete a key from a Trie.
        // level: level (or depth) of a Trie
        bool deleteHelper(TrieNode *pNode, string key, int level, int len) {
            if(pNode) {
                // Base Case
                if(level == len) {
                    // Unmark leaf node
                    pNode -> isWord = false;

                    // If empty, node to be deleted
                    if(isFreeNode(pNode)) {
                        return true;
                    }
                    // not empty, should not delete the node.
                    return false;
                }
                else { // Recursive case
                    if(deleteHelper(pNode->next[key[level] - 'a'], key, level + 1, len)) {
                        // last node marked, delete it.
                        delete pNode->next[key[level] - 'a'];

                        // recursively climb up, and delete eligible node.
                        return ((!isLeafNode(pNode)) && isFreeNode(pNode));
                    }
                }
            }
            return false;
        }
    	TrieNode* root;
};

int main() {
    string keys[8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    Trie trie;
    for(int i = 0; i < 8; i++) {
        trie.insert(keys[i]);
    }
    cout << trie.search("she") << endl;
    trie.deleteKey(keys[0]);
    cout << trie.search("she") << endl;
    return 0;
}

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
    public:
        vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string>& wordDict) {
            queue<string> toVisit;
            vector<vector<string> > res;
            vector<string> curr, next;
            wordDict.insert(endWord);
            addNextWord(beginWord, wordDict, toVisit);

            while(!toVisit()) {
                for(int i = 0; i < toVisit.size(); i++) {
                    string word = toVisit.front();
                    toVisit.pop();
                    next.push_
                }
            }

        }
    private:
        void addNextWord(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
            wordDict.erase(word);
            
            for(int i = 0; i < word.size(); i++) {
                char letter = word[i];
                for(int k = 0; k < 26; k++) {
                    word[i] = 'a' + k;
                    if(wordDict.find(word) != wordDict.end()) {
                        wordDict.erase(word);
                        toVisit.push(word);
                    }
                }
                word[i] = letter;
            }
        }
};

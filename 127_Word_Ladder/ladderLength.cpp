#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
            wordDict.insert(endWord);
            queue<string> toVisit;
            addNextWords(beginWord, wordDict, toVisit);
            int dist = 2;
            while(!toVisit.empty()) {
                int num = toVisit.size();
                for(int i = 0; i < num; i++) {
                    string word = toVisit.front();
                    toVisit.pop();
                    if(word == endWord) { return dist; }
                    addNextWords(word, wordDict, toVisit);
                }
                dist++;
            }

            return 0;
        }
    private:
        void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
            wordDict.erase(word);
            for(int i = 0; i < word.size(); i++) {
                char letter = word[i];
                for(int k = 0; k < 26; k++) {
                    word[i] = 'a' + k;
                    if(wordDict.find(word) != wordDict.end()) {
                        toVisit.push(word);
                        wordDict.erase(word);
                    }
                }
                word[i] = letter;
            }
        }

};

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> generateAbbreviations(string word) {
            vector<string> res;
            dfs(res, word, "", 0, 0);
            return res;
        }
    
    private:
        // count : number of character abbreviated
        void dfs(vector<string>& res, string& word, string curr, int pos, int count) {
            if(pos == word.size()) {
                if(count > 0) {
                    curr += to_string(count);
                }

                res.push_back(curr);
                return;
            }

            // abbrebriate word[pos]
            dfs(res, word, curr, pos + 1, count + 1);
            // do not abbrebriate word[pos]
            dfs(res, word, curr + ((count > 0)? to_string(count) : "") + word[pos], pos + 1, 0);

        }
};


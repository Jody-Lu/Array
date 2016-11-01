class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1;
        int res = words.size();
        for(int i = 0; i < words.size(); i++) {
            if(word1 == word2) {
                if(words[i] == word1) {
                    // By doing this, we can get two position we need
                    idx2 = idx1; // store idx1's value first
                    idx1 = i; // change idx1' value
                }
            }
            else {
                if(words[i] == word1) idx1 = i;
                if(words[i] == word2) idx2 = i;
            }
            if(idx1 != -1 && idx2 != -1)
                res = min(res, abs(idx1 - idx2));
        }
        return res;
    }
};
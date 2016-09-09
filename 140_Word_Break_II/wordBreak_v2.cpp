#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string>& dict) {
            if(m.count(s)) return m[s];
            vector<string> result;
            if(dict.count(s)) {
                result.push_back(s);
            }
            for(int i = 1; i < s.size(); i++) {
                string word = s.substr(i);
                if(dict.count(word)) {
                    string rem = s.substr(0, i);
                    vector<string> prev = combine(word,wordBreak(rem,dict));
                    result.insert(result.end(),prev.begin(), prev.end());
                }
            }
            m[s] = result;
            return result;
        }
    private:
        unordered_map<string, vector<string> > m;
        
        vector<string> combine(string word, vector<string> prev) {
            for(int i = 0; i < prev.size(); i++) {
                prev[i] += " " + word; 
            }
            return prev;
        }
    
};

int main() {
    return 0;
}

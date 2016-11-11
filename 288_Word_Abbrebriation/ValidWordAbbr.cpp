#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(string& word : dictionary) {
            int len = word.size();
            string abbr = word[0] + to_string((len - 2)) + word[len - 1];
            m[abbr].insert(word);
        }
    }
    
    // Corner Case: when check the word not in m, we should return true; 
   
    bool isUnique(string word) {
        int len = word.size();
        string abbr = (len <= 2)? word : (word[0] + to_string((len - 2)) + word[len - 1]);
        return m[abbr].count(word) == m[abbr].size();
    }
private:
    unordered_map<string, unordered_set<string> > m;
};

int main() {
    string strs[1] = {"hello"};
    vector<string> dictionary(strs, strs + 1);
    ValidWordAbbr vwa(dictionary);
    cout << vwa.isUnique("") << endl;
}

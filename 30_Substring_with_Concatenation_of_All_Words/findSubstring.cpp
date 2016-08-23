#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> result;
            map<string, int> need;
            int missing = words.size();
            int begin = 0, end = 0;
            int len = words[0].size(), num = words.size(); // word's length

            // Initialize the map
            for(int k = 0; k < num; k++)
                need[words[k]]++;

            while(end < s.size() - num * len + 1) {
                /* Set begin to the head of word we meet. */
                begin = end;
                while(need[s.substr(end, len)] > 0) {
                    missing--;
                    need[s.substr(end, len)]--;
                    end += len;
                }
                /* tmp_end is used to store end for reseting some parameters. */
                int tmp_end = end;
                /* missing == 0: we find all the words and they are concatenated together. */
                if(missing == 0)
                    result.push_back(begin);
                /* Set end to the next of begin. */
                end = begin + 1;

                /* Reset here. */
                missing = num;
                while(begin < tmp_end) {
                    need[s.substr(begin, len)]++;
                    begin += len;
                }
            }
            return result;
        }
};

int main() {
    Solution sol;
    string s = "aaaaaaaa"; //"barfoofoobarthefoobarman";
    string arr[] = {"aa", "aa", "aa"};
    vector<string> words(arr, arr+3);
    vector<int> res; 
    cout << s << endl;
    res = sol.findSubstring(s, words);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}

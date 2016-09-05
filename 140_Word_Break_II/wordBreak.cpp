#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
            int len = s.size();
            vector<bool> dp(len + 1, false);
            vector<string> res;
            dp[0] = true;

            for(int i = 0; i <= len; i++) {
                for(string w: wordDict) {
                    int sub_len = w.size();
                    if(i + sub_len <= len &&
                       w == s.substr(i, sub_len) &&
                       !dp[i + sub_len])
                        dp[i + sub_len] = true & dp[i];
                }
            }

            for(int i = 0; i < dp.size(); i++) {
                cout << dp[i] << " ";
            }
            cout << endl;
            return res;
        }
};


int main() {
    /*
    string s = "catsanddog";
    string arr[] = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> wordDict(arr, arr + 5);
    Solution sol;
    sol.wordBreak(s, wordDict);
    */
    string s = "abcde";
    cout << s.substr(1) << endl;
}

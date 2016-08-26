#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	public:
    	bool wordBreak(string s, unordered_set<string>& wordDict) {
            if(wordDict.size() == 0) return false;
            vector<int> dp(s.size() + 1, false);
            int len = s.size();
            dp[0] = true;
            for(int i = 0; i < len; i++) {
                for(string w: wordDict) {
                    int sub_len = w.size();
                    /* i + sub_len must not be greater than len. */
                    /* If dp[i + sub_len] has been travered, do not traverse again. */
                    if(i + sub_len <= len && 
                       w == s.substr(i, sub_len) &&
                       !dp[i + sub_len])
                        dp[i + sub_len] = true & dp[i];
                }
            }
            return dp[len];
    	}
};

int main() {
    string s = "leetcode";
    string arr[] = {"leet", "code"};
    unordered_set<string> wordDict(arr, arr+2);
    Solution sol;
    cout << sol.wordBreak(s, wordDict) << endl;
}

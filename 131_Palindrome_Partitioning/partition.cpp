#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        dfs(res, 0, s, vector<string>());
        return res;
    }
private:
    bool isPalindrome(string s, int right, int left) {
        int begin = left, end = right - 1;
        while(begin < end) {
            if(s[begin] != s[end])
                return false;
            else {
                begin++;
                end--;
            }
        }
        return true;
    }
    void dfs(vector<vector<string> > &res, int begin, string s, vector<string> strs) {
        if(begin >= s.size())
            res.push_back(strs);

        for(int i = begin + 1; i <= s.size(); i++) {
            if(isPalindrome(s, i, begin)) {
                strs.push_back(s.substr(begin, i - begin));
                dfs(res, i, s, strs);
                strs.pop_back();
            }
        }
    }
};
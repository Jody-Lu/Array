#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
    public:
        int longestPalindrome(string s) {
            if(s.size() == 0) return 0;
            map<char, int> counts;
            int res = 0;
            for(int i = 0; i < s.size(); i++)
                counts[s[i]]++;

            for(auto it = counts.begin(); it != counts.end(); it++)
                // # (it -> first) is even, include all.
                if(it->second % 2 == 0)
                    res += it -> second;
                // # (it -> first) is odd, include (all - 1).
                else
                    res += (it -> second) - 1;
            return (res == s.size())? res : res + 1;
        }
};

int main() {
    Solution sol;
    string s = "abccccdd";
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}

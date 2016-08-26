#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;

/* f[i]: longest valid parentheses till index i*/
/* f[0] = 0 */
/* f[1] = 0 if s[0] == ')' or s[0] == s[1]. */

class Solution {
    public:
        int longestValidParentheses(string s) {
            vector<int> longest(s.size(), 0);
            int curMax = 0;
            for(int i = 1; i < s.size(); i++) {
                if(s[i] == ')') {
                    if(s[i - 1] == '(') {
                        longest[i] = (i-2) >= 0? longest[i-2] + 2 : 2;
                        curMax = max(curMax, longest[i]);
                    }
                    else {
                        if(i - longest[i-1] - 1 >= 0 && s[i - longest[i-1] - 1] == '(') {
                            longest[i] = longest[i-1] + 2 + \
                                         ((i-longest[i - 1]-2) >= 0? longest[i - longest[i - 1] - 2] : 0);
                            curMax = max(curMax, longest[i]);
                        }
                    }
                }
            }
            return curMax;
        }
};

int main() {
    Solution sol;
    string s = ")()())";
    cout << s << endl;
    cout << sol.longestValidParentheses(s) << endl;
}

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
            if(s.size() == 0 || s.size() == 1) return 0;
            map<int, int> leftCount; // number of '(' till index i
            vector<int> f(s.size(), 0);
            leftCount[0] = s[0] == '('? 1 : 0;
            
            for(int i = 1; i < s.size(); i++) {
                leftCount[i] = (s[i] == '('? 1 : 0) + leftCount[i - 1];
            }
            
            /*
            for(int i = 1; i < s.size(); i++) {
                if(s[i] == ')' && leftCount[i- 1] == 0) f[i] = f[i - 1];
                if(s[i] == ')' && leftCount[i - 1] >= 1) {
                    f[i] = 2 + f[i - 1];
                    leftCount[i - 1]--;
                }
            }
            */
            for(int i = 0; i < f.size(); i++) {
                cout << f[i] << " ";
            }
            cout << endl;
            return f[s.size() - 1];
        }
};

int main() {
    Solution sol;
    string s = ")()()(";
    cout << s << endl;
    cout << sol.longestValidParentheses(s) << endl;

}

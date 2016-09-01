#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            // T[i][j] is true if first i character in given string
            // matches the first j characters of pattern.
            int m = s.size(), n = p.size();
            vector<vector<bool> > T(m + 1, vector<bool>(n + 1, false));
            /* both text and pattern are NULL. */
            T[0][0] = true;

            /* pattern is NULL. */
            for(int i = 1; i <= m; i++)
                T[i][0] = false;

            /* text is NULL. */
            for(int j = 1; j <= n; j++)
                if(p[j - 1] == '*')
                    T[0][j] = T[0][j - 1];

            /* DP relation */
            for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= n; j++) {
                    /* current cahracter matches. */
                    if((p[j - 1] == '?') || p[j - 1] == s[i - 1])
                        T[i][j] = T[i - 1][j - 1];
                    else if(p[j - 1] == '*')
                        T[i][j] = T[i][j - 1] || T[i - 1][j];
                    else
                        T[i][j] = false;
                }
            }
            /*
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= n; j++)
                    cout << T[i][j] << " ";
                cout << endl;
            }
            */

            return T[m][n];
        }
};
int main() {
    Solution sol;
    string s = "aa";
    string p = "a*";
    cout << sol.isMatch(s, p) << endl; 
}

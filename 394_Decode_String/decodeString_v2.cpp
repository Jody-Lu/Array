#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string decodeString(string s, int& i) {
            string res;
            //static int i = 0;
            while(i < s.length() && s[i] != ']') {
                if(!isdigit(s[i]))
                    res += s[i++];
                else {
                    /* Calculate the digits. */
                    int n = 0;
                    while (i < s.length() && isdigit(s[i]))
                        n = n * 10 + s[i++] - '0';

                    i++; // '['
                    string t = decodeString(s, i);
                    i++; // ']'

                    while(n--) res += t;
                }
            }
            return res;
        }
        string decodeString(string s) {
            int i = 0;
            return decodeString(s, i);
        }
};

int main() {
    Solution sol;
    string s = "2[abc]3[cd]ef";
    cout << sol.decodeString(s) << endl;
}

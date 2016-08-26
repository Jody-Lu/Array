#include <iostream>
#include <string>


using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int i = 0, j = 0;
            while(i < s.size() && j < p.size()) {
                if(s[i] == '*' || p[j] == '*')
                    return true;
                if(s[i] == p[j]) {
                    i++;
                    j++;
                    continue;
                }
                if((s[i] == '?' && p[j] != '*' ) || (s[i] != '*' && p[j] == '?' )) {
                    i++;
                    j++;
                    continue;
                }
                if(s[i] != p[j]) return false;
            }
            return (i == s.size()) && (j == p.size()) ;
        }
};

int main() {
    string s = "aab";
    string t = "c*a*b";
    Solution sol;
    cout << sol.isMatch(s, t) << endl;
}

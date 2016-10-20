#include <iostream>
#include <string>


using namespace std;

class Solution {
    public:
        string shortestPalindrome(string s) {
            string s2 = s;
            reverse(s2.begin(), s2.end());
            int n = s2.size(), l;
            for(l = n; l >= 0; l--) {
                if(s.substr(0, l) == s2.substr(n - l)) // is palindrome
                    break;
            }
            return s2.substr(0, n - l).append(s);
        }
};

int main() {
    string s = "abcd";
    Solution sol;
    cout <<  sol.shortestPalindrome(s) << endl;
}

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int myAtoi(string s) {
            int idx = 0;
            long res = 0;
            int sign = 1;
            int count = 0; // Count number of digits.
            while(s[idx] == ' ') idx++; // Remove spaces.
            /* Check the first digit is either '+' or '-'. */
            if(s[idx] == '+') idx++; 
            else if(s[idx] == '-') {
                idx++;
                sign = -1;
            }
            while(idx < s.size()) {
                if(isdigit(s[idx])) {
                    res *= 10;
                    res += (int)(s[idx] - '0');
                    idx++;
                    count++;
                }
                else
                    break;
            }
            /* If #digits > 10, overflow.*/
            if(count > 10 || res > INT_MAX)
                return sign == 1? INT_MAX : INT_MIN;

            if(res <= INT_MAX && res >= INT_MIN)
                return sign * res;

            return 0;
        }
};

int main() {
    string s = "   a1776a";
    Solution sol;
    cout << sol.myAtoi(s) << endl;
}

#include <iostream>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            /* Negative number is not palindrome. */
            if(x < 0) return false;
            /* x < 10, x must be palindrome. */
            if(x < 10) return true;
            int top = 1, bottom = 10;
            /* Calculate x's number of digits. */
            while(x / top >= 10) top *= 10;
            while(x) {
                /* x / top: left most digit. */
                /* x % bottom: right most digit. */
                if(x / top != x % bottom)
                    return false;
                x %= top;
                x /= bottom;
                /* x loses 2 digits each interation. */
                top /= 100;
            }
            return true;
        }
};

int main() {
    int x = 1;
    Solution sol;
    cout << sol.isPalindrome(x) << endl;

}

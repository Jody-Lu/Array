#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Solution {
    public:
        int findNthDigit(int n) {
            /* calculate how maniy digits the number has. */
            long base = 9, digits = 1;
            while(n - base * digits > 0) {
                n -= base * digits;
                base *= 10;
                digits++;
            }

            /* calculate what the muber is */
            int index = n % digits;
            if(index == 0) index = digits;

            long num = 1;
            for(int i = 1; i < digits; i++)
                num *= 10;

            num += (index == digits)? n / digits - 1 : n / digits;

            int res = to_string(num)[index - 1] - '0';
            return res;
        }
};

int main() {
    Solution sol;
    cout << sol.findNthDigit(15) << endl;
    return 0;
}

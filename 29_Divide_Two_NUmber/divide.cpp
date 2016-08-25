#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
    public:
        int divide(int dividend, int divisor) {
            /* abs(INT_MIN) = INT_MAX + 1 */
            if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
                return INT_MAX;
            int sign = ((dividend < 0) ^ (divisor < 0))? -1 : 1;
            ll dvd = labs(dividend);
            ll dvs = labs(divisor);
            int res = 0;
            /* O(log(N)) */
            while(dvd >= dvs) {
                ll tmp = dvs, multiple = 1;
                /* O(log(N)) */
                while((tmp << multiple) <= dvd)
                    multiple++;
                dvd -= (dvs << (multiple - 1));
                res += (1 << (multiple - 1));
            }
            return res * sign;
        }
};

int main() {
    Solution sol;
    int dividend = 2;
    int divisor = 3;
    cout << sol.divide(dividend, divisor) << endl;
}

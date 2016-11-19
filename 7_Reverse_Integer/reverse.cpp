#include <iostream>

using namespace std;

class Solution {
	public:
    	int reverse(int x) {
            /* Since res may be bigger than INT_MAX or smaller than INT_MIN. */
            long res = 0;
            int sign = x > 0? 1 : -1;
            x = abs(x);
            while(x) {
                res = res * 10 + x % 10;
                x /= 10;
            }

            return (res <= INT_MAX && res >= INT_MIN)? res * sign : 0;

    	}
};

int main() {
    return 0;
}

#include <iostream>

using namespace std;
/*
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int fac = 5;
        while(fac <= n) {
            int tmp = fac;
            while(tmp % 5 == 0) {
                res += 1;
                tmp /= 5;
            }
            fac += 5;
        }
        return res;
    }
};
*/
class Solution {
public:
    int trailingZeroes(int n) {
        /* Count number of 5. */
        return n == 0? 0 : n /5 + trailingZeroes(n/5);
    }
};

int main() {
	Solution sol;
	int x = 1808548329;
	cout << sol.trailingZeroes(x) << endl;

}

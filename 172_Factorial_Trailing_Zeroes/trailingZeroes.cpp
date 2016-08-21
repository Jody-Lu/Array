#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        /* Count number of 5. */
        int res = 0;
        while(n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};


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

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string convertToTitle(int n) {
            string res = "";
            while(n) {
                /* Since if n == 26, n % 26 == 0, we count from 'A' and n -= 1. */
                res = char(--n % 26 + 'A') + res;
                n /= 26;
            }
            return res;
        }
};

int main() {
    int n = 26;
    Solution sol;
    cout << sol.convertToTitle(n) << endl;
}

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
    public:
        int superPow(int a, vector<int>& b) {
            int n = b.size() - 1, ans = 1;
            for(int i = n; i >= 0; i--) {
                ans = ans * myPow(a, b[i]) % 1337;
                a = myPow(a, 10);
            }
            return ans;
        }
    private:
        int myPow(int x, int n) {
            int res = 1;
            x %= 1337;
            while(n > 0) {
                /* Check that n is either even or odd. */
                if(n & 1) res = res * x % 1337;
                x = x * x % 1337;
                n >>= 1;
            }
            return res;
        }

};

int main() {
    Solution sol;
    int a = 2;
    int arr[] = {1, 0, 0, 0};
    vector<int> b(arr, arr + 4);
    cout << sol.superPow(a, b) << endl;
}

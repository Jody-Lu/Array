#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
    public:
        int superPow(int a, vector<int>& b) {
            reverse(b.begin(), b.end());
            int res = 1;
            for(int i = 0; i < b.size(); i++) {
                res = res * myPow(a, b[i]) % 1337;
                a = myPow(a, 10) % 1337;
            }
            return res;
        }
        int myPow(int x, int n) {
            if(n == 0) return 1;
            int val = myPow(x, n/2);
            return n % 2 == 0? (val * val) % 1337 : (x * val * val) % 1337;
        }
        /* Iteration O(n)
        int superPow(int a, vector<int>& b) {
            long res = 1;
            int digit = 1;
            reverse(b.begin(), b.end());

            for(int i = 0; i < b.size(); i++) {
                int power = digit * b[i], j = 1;
                while(j <= power) {
                    res *= a;
                    res %= 1337;
                    j++;
                }
                digit *= 10;
            }
            return res;
        }
        */
};

int main() {
    Solution sol;
    int a = 2;
    int arr[] = {1, 0, 0, 0};
    vector<int> b(arr, arr + 4);
    cout << sol.superPow(a, b) << endl;
}

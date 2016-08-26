#include <iostream>

using namespace std;

class Solution {
    public:
        int getSum(int a, int b) {
            int sum, carry;
            if(b == 0) return a;
            sum = a ^ b;
            carry = (a & b) << 1;
            return getSum(sum, carry);
        }
};

int main() {
    int a = 3;
    int b = 5;
    Solution sol;
    cout << sol.getSum(a, b) << endl;
}

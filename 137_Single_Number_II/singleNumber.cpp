#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int x1 = 0;
            int x2 = 0;
            int mask = 0;
            for(int i = 0; i < nums.size(); i++) {
                x2 ^= x1 ^ i;
                x1 ^= i;
                mask = ~(x1 & x2);
                x2 &= mask;
                x1 &= mask;
            }
            return x1;
        }
};

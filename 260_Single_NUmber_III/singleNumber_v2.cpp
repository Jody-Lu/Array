#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            int XOR = nums[0];
            int set_bit_no;
            int i;
            int x = 0, y = 0;
            int n = nums.size();

            for(i = 1; i < n; i++) {
                XOR ^= nums[i];
            }

            set_bit_no = XOR & ~(XOR - 1);

            for(i = 0; i < n; i++) {
                if(nums[i] & set_bit_no) {
                    x = x ^ nums[i];
                }
                else {
                    y = y ^ nums[i];
                }
            }

            return vector<int>{x, y};
        }
};

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> singleNumber(vector<int>& nums) {
            int diff = accumulate(nums.begin(), nums.end(), bit_xor<int>());
            diff &= -diff;

            vector<int> res = {};
            for(int i = 0; i < nums.size(); i++) {
                if((nums[i] & diff) == 0) {
                    res[0] ^= nums[i];
                }
                else {
                    res[1] ^= nums[i];
                }
            }
            return res;
		}
};

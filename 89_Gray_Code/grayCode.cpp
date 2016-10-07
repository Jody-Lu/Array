#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
    public:
        void utils(bitset<32>& bits, vector<int>& res, int k) {
            if(k == 0) {
                res.push_back(bits.to_ulong());
            }
            else {
                utils(bits, res, k - 1);
                bits.flip(k - 1);
                utils(bits, res, k - 1);
            }
        }
        vector<int> grayCode(int n) {
            vector<int> res;
            bitset<32> bits;
            utils(bits, res, n);
            return res;
        }
};


int main() {
    Solution sol;
    int n = 3;

}

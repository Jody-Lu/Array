#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        vector<int> nums;
    public:
        Solution(vector<int> nums) {
            this -> nums = nums;
        }

        /** Resets the array to its original configuration and return it. */
        vector<int> reset() {
            return nums;
        }

        /** Returns a random shuffling of the array. */
        vector<int> shuffle() {
            vector<int> res(nums);
            for(int i = 0; i < res.size(); i++) {
                int pos = rand() % (res.size() - i);
                swap(res[i], res[i + pos]);
            }
            return res;
        }
};

int main() {
    
}

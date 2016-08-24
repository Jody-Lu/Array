#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
           return majority(nums, 0, nums.size() - 1);
        }
    private:
        int majority(vector<int>& nums, int begin, int end) {
            if(begin < end) {
                /* Divide. */
                int mid = begin + ((end - begin) >> 1);
                int lmajor = majority(nums, begin, mid);
                int rmajor = majority(nums, mid + 1, end);
                /* Merge. */
                if(lmajor== rmajor) return lmajor;
                return count(nums.begin() + begin, nums.begin() + end + 1, lmajor) > \
                       count(nums.begin() + begin, nums.begin() + end + 1, rmajor) ? lmajor : rmajor;

            }
            else return nums[begin];
        }

};

int main() {
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int n = nums.size();
            if(nums.size() == 0) return 0;
            int begin = 0, forward = 0;
            while(++forward < n) {
                if(nums[forward] != nums[begin])
                    nums[++begin] = nums[forward];
            }

            nums.erase(nums.begin() + begin + 1, nums.end());
            return nums.size();
        }
};

int main() {
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            nth_element(nums.begin(), nums.size() / 2, nums.end());
            return nums[nums.size() / 2];
        }
};

int main() {
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;


class Solution {
	public:
    	int removeElement(vector<int>& nums, int val) {
            int begin = -1, forward = -1;
            while(++forward < nums.size()) {
                if(nums[forward] != val)
                    nums[++begin] = nums[forward];
            }
            nums.erase(nums.begin() + begin + 1, nums.end());
            return nums.size();
    	}
};

int main() {
    return 0;
}

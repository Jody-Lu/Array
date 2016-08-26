#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int major, counts = 0, n = nums.size();
            for(int i = 0; i < n; i++) {
                if(!counts) {
                    major = nums[i];
                    counts++;
                }
                else counts += (nums[i] == major)? 1 : -1;
            }
            return major;
        }

};

int main() {
    return 0;
}

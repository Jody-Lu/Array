#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        string getRange(int start, int end) {
            return (start == end)? to_string(start) : (to_string(start) + "->" + to_string(end));
        }
    public:
        vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
            vector<string> res;
            long pre = lower - 1, curr;
            for(int i = 0; i <= nums.size(); i++) {
                curr = (i == nums.size())? (upper + 1) : nums[i];
                if((curr - pre) >= 2) {
                    res.push_back(getRange(pre + 1, curr - 1));
                }
                pre = curr;
            }
            return res;
        }
};
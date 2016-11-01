class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.size() == 0) {
            if(lower != upper) {
                res.push_back(to_string(lower) + "->" + to_string(upper));
            }
            else {
                res.push_back(to_string(lower));
            }
            return res;
        }
        
        if((nums[0] - lower) >= 2) {
            res.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
        }
        else if((nums[0] - lower) == 1) {
            res.push_back(to_string(lower));
        }
        
        for(int i = 1; i < nums.size(); i++) {
            if((nums[i] - 1) != (nums[i - 1] + 1) && (nums[i - 1] + 1) != nums[i] && nums[i] != nums[i - 1]) {
                res.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
            }
            else if((nums[i] - nums[i - 1]) == 2) {
                res.push_back(to_string(nums[i - 1] + 1));
            }
        }
        
        if((upper - nums.back()) >= 2) {
            res.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
        }
        else if((upper - nums.back()) == 1) {
            res.push_back(to_string(upper));
        }
        
        return res;
    }
};
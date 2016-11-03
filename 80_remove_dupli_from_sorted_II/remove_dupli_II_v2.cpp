class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int begin = 2, forward = 1;
        int n = nums.size();
        if(n < 2) { return n; }
        
        while(++forward < n) {
            if(nums[begin - 2] != nums[forward]) {
                nums[begin++] = nums[forward];
            }
        }
        
        nums.erase(nums.begin() + begin, nums.end());
        return nums.size();
    }
};
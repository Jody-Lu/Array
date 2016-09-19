class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int g1 = INT_MAX, g2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= g1)
                g1 = nums[i];
            else if(nums[i] <= g2)
                g2 = nums[i];
            else
                return true;
        }
        return false;
    }
};
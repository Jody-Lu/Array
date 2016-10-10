class Solution {
public:
    /* Care duplicate term*/
    int thirdMax(vector<int>& nums) {
        if(nums.size() < 3) {
            int maxR = INT_MIN;
            for(int i = 0; i < nums.size(); i++)
                maxR = max(maxR, nums[i]);
            return maxR;
        }
        int top[3] = {INT_MIN, INT_MIN, INT_MIN};
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > top[0] && nums[i] != top[0] && nums[i] != top[1] && nums[i] != top[2]) {
                top[0] = nums[i];
                if(top[0] > top[1])
                    swap(top[0], top[1]);
                if(top[1] > top[2])
                    swap(top[1], top[2]);
            }
        }
        return top[0];
    }
};
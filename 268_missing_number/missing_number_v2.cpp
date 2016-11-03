class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), end = n - 1;
        
        // if not segregate means there is no 0, then return 0. 
        if(!segregate(nums)) {
            return 0;
        }
        
        // make the viisted element negative.
        for(int i = 0; i < end; i++) {
            if((abs(nums[i]) - 1) < n && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        
        // Find the positive one
        for(int i = 0; i < end; i++) {
            if(nums[i] >= 0) {
                return (i + 1);
            } 
        }
        
        return (end + 1);
    }
private:
    bool segregate(vector<int>& nums) {
        int n = nums.size();
        int j = n - 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[j]);
                return true;
            }
        }
        return false;
    }
};
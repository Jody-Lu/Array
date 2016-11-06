class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        
        for(int i = 0; i < (n - 2); i++) {
            int j = i + 1, k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum >= target) { k--; }
                else {
                    res += (k - j);
                    j++;
                }
            }
        }
        
        return res;
    }
};

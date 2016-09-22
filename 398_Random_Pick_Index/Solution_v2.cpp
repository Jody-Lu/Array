class Solution {
	public:
    	Solution(vector<int> nums) {
            this -> nums = nums;
    	}

    	int pick(int target) {
            int i = 0;
            int n = nums.size();
            int res = 0;

            /* Find the first target. */
            for(; i < n; i++) {
                if(nums[i] == target) {
                    res = i;
                    break;
                }
            }
            i++; // move i to the next

            /* Reservoir Sampling. */
            int count = 2;
            for(; i < n; i++) {
                if(nums[i] == target) {
                    int j = rand() % count;
                    if(j == 0) res = i;
                    count++;
                }
            }

            return res;
    	}
    private:
        vector<int> nums;
};
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int k, j;
        for(int i = nums.size() - 1, k = i / 2 + 1, j = 0; i >= 0; i--) {
            nums[i] = sorted[(i & 1)? k++ : j++];
        }
    }
};
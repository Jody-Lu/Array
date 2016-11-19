class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        if(n == 0) { return res; }
        int i = 0;
        while(i < n) {
            int start = i, end = i;
            while((end + 1) < n && nums[end + 1] == 1 + nums[end]) { end++; }
            if(end > start) {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }
            else {
                res.push_back(to_string(nums[end]));
            }
            i = end + 1;
        }

        return res;
    }
};
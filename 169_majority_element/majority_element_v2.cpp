class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> counts;
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(++counts[nums[i]] > n/2) { 
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(res, nums, sub, 0);
        return res;
    }

private:
    void subsetsWithDupHelper(vector<vector<int> >& res, vector<int>& nums, vector<int>& sub, int start) {
        res.push_back(sub);

        for(int i = start; i < nums.size(); i++) {
            if(i != start && nums[i] == nums[i - 1]) { continue; }
            sub.push_back(nums[i]);
            subsetsWithDupHelper(res, nums, sub, i + 1);
            sub.pop_back();
        }
    }
};
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int> > res;
            dfs(nums, 0, res);
            return res;
        }
    private:
        void dfs(vector<int> nums, int start, vector<vector<int> > &res) {
            if(start >= nums.size()) {
                res.push_back(nums);
                return;
            }

            for(int i = start; i < nums.size(); i++) {
                if(start != i && nums[start] == nums[i]) { continue; }
                swap(nums[start], nums[i]);
                dfs(nums, start + 1, res);
            }
        }
};

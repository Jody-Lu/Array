#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
    	vector<vector<int> > permute(vector<int>& nums) {
        	vector<vector<int> > res;
            dfs(res, nums, 0);
            return res;
    	}
    private:
        void dfs(vector<vector<int> > &res, vector<int> &nums, int begin) {
            if(begin >= nums.size()) {
                res.push_back(nums);
                return;
            }

            for(int i = begin; i < nums.size(); i++) {
                swap(nums[begin], nums[i]);
                dfs(res, nums, begin + 1);
                swap(nums[begin], nums[i]);
            }
        }
};

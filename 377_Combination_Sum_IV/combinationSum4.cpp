#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
    	int combinationSum4(vector<int>& nums, int target) {
            vector<int> dp(target + 1);
            sort(nums.begin(), nums.end());
            dp[0] = 1;
            for(int i = 1; i <= target; i++) {
                for(int j = 0; j < nums.size(); j++) {
                    if(i >= nums[j])
                        dp[i] += dp[i - nums[j]];
                    else break;
                }
            }
            return dp[target];
    	}
};

int main() {
    Solution sol;
    int arr[] = {4, 2, 1};
    int target = 32;
    vector<int> nums(arr, arr + 3);
    cout << sol.combinationSum4(nums, target) << endl;
}

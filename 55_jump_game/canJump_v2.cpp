#include <vector>

using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            if(nums[0] == 0 && n > 0)
                return false;

            vector<int> dp(n, false);
            dp[0] = true;

            for(int i = 1; i < n; i++) {
                for(int j = i - 1; j >= 0; j--) {
                    dp[i] = dp[j] && (nums[j] >= (j - i));
                }
            }
            return dp[n - 1];
        }
};

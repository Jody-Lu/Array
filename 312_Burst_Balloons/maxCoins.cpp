#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // i-1 < 0 or i+1 >=n --> nums[i - 1] == nums[i + 1] = 1
        int maxCoins(vector<int>& nums) {
            if(nums.size() == 0) return 0;
            if(nums.size() == 1) return nums[0];
            int len = nums.size();
            vector<int> dp(len + 1, 0);
            dp[0] = 0;
            dp[1] = nums[0];
            dp[2] = nums[0] * nums[1];
            
            for(int i = 3; i <= len; i++) {
                if(i != len)
                    dp[i] = max(dp[i - 1], nums[i] * nums[i - 1] * nums[i - 2] + dp[i - 2]);
                else
                    dp[i] = max(dp[i - 1], nums[i - 1] * nums[i - 2] + dp[i - 2]);
            }

            for(int i = 0; i < dp.size(); i++)
                cout << dp[i] << " ";
            cout << endl;
            return dp[len];
        }
};

int main() {
    int arr[] = {3, 1, 5, 8};
    vector<int> nums(arr, arr + 4);
    Solution sol;
    cout << sol.maxCoins(nums) << endl;
}

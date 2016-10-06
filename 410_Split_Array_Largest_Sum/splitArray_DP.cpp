#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int splitArray(vector<int> &nums, int m) {
            int n = nums.size();
            // DP[i][j]: the solution to divide nums[j] ~ nums[L-1] into i parts.
            vector<int> dp(n, 0);
            vector<int> sums(n + 1, 0);

            for(int i = 0; i < n; i++)
                sums[i + 1] = sums[i] + nums[i];


            for(int i = 0; i < n; i++)
                dp[i] = sums[n] - sums[i];

            for(int s = 1; s < m; s++) {
                for(int i = 0; i < (n - s); i++) {
                    dp[i] = INT_MAX;
                    for(int j = i + 1; j <= n - s; j++) {
                        int t = max(dp[j], sums[j] - sums[i]);
                        if(t <= dp[i])
                            dp[i] = t;
                        else
                            break;
                    }

                }
            }
            return dp[0];
        }
};

int main() {
    return 0;
}

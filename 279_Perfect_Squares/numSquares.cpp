#include <iostream>
#include <vector>


using namespace std;

// 1-D DP
// space: O(n)
class Solution {
    public:
        int numSquares(int n) {
            // dp[i]: #square to construct i
            vector<int> dp(n + 1, 0);
            
            int i = 0, j, val;

            // base case
            while(i * i <= n) {
                dp[i * i] = 1;
                i++;
            }

            // general case
            for(int i = 0; i <= n; i++) {
                j = 1;
                while(i + j * j <= n) {
                    val = i + j * j;
                    dp[val] = min(dp[i] + 1, dp[val]);
                    j++;
                }
            }

            return dp[n];
        }
};

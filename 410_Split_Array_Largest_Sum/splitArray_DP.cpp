#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int splitArray(vector<int> &nums, int m) {
            int n = nums.size();
            // DP[i][j]: the solution to divide nums[j] ~ nums[L-1] into i parts.
            vector<vector<int> > DP(m, vector<int>(n, 0));
            vector<int> sums(n + 1, 0);
            
            for(int i = 1; i <= n; i++)
                sums[i] = sums[i - 1] + nums[i - 1];

            // Divide into one part --> m = 0
            for(int i = 0; i < n; i++)
                DP[0][i] = sums[n] - sums[i];


            
            

        }
};

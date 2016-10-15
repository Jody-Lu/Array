#include <vector>

using namespace std;

class Solution {
    public:
        int minimumTotal(vector<vector<int> >& triangle) {
            int n = triangle.size();
            vector<vector<int> > dp(n, vector<int>(n, 0));
            int minSum = INT_MAX;
            int i, j;

            // base case
            dp[0][0] = triangle[0][0];

            // the left side
            for(i = 1; i < n; i++)
                dp[i][0] = triangle[i][0] + dp[i - 1][0];

            // the right side
            for(i = 1; i < n; i++) {
                int len = triangle[i].size();
                dp[i][len - 1] = triangle[i][len - 1] + dp[i - 1][triangle[i-1].size() - 1]; 
            }

            // general case
            for(i = 1; i < n; i++) {
                for(j = 1; j < triangle[i].size() - 1; j++) {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }

            for(i = 0; i < triangle[n - 1].size(); i++) {
                minSum = min(minSum, dp[n - 1][i]);
            }

            return minSum;
        }
};

int main() {
    return 0;
}

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
    public:
        int maxEnvelopes(vector<pair<int, int>>& envelopes) {
            int n = envelopes.size();
            // dp[i][j]: max between ith envelope and jth envelope
            vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
            for(int len = 1; len <= n; len++) {
                for(int left = 0; left <= n - len + 1; left++) {
                    int right = len + left - 1;
                    for(int k = left; k <= right; k++) {
                        if(len == 1) dp[left][right] = 1;
                        else if() {}
                    }
                }
            }
        }
};

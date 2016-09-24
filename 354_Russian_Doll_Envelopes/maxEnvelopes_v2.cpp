#include <iostream>
#include <utility>

using namespace std;

bool cmp(pair<int, int> i, pair<int, int> j) {
    if(i.first == j.first)
        // If the firsts are the same, the second ordered by decreasing order.
        return i.second > j.second;
    return i.first < j.first;
}

class Solution {
    public:
        int maxEnvelopes(vector<pair<int, int>>& envelopes) {
            int N = envelopes.size();
            vector<int> dp(N, 1);
            int mx = (N == 0) ? 0 : 1;
            sort(envelopes.begin(), envelopes.end(), cmp);

            for(int i = 0; i < N; i++) {
                for(int j = i - 1; j >= 0; j--) {
                    if(envelopes[i].second > envelopes[j].second) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        mx = max(dp[i], mx);
                    }
                }
            }
            return mx;
        }
};

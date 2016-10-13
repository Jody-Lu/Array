#include <vector>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // f[k][i]: the max profit up until prices[i] (not include prices[i])
            // by k times transaction.
            int maxPro = 0;
            if(prices.size() <= 1) return 0;
            else {
                int K = 2; // max times of transactions
                vector<vector<int> > f(K + 1, vector<int>(prices.size(), 0));
                for(int k = 1; k <= K; k++) {
                    int tmpMax = f[k - 1][0] - prices[0];
                    for(int i = 0; i < prices.size(); i++) {
                        f[k][i] = max(f[k][i - 1], prices[i] + tmpMax);
                        tmpMax = max(tmpMax, f[k - 1][i] - prices[i]);
                        maxPro = max(maxPro, f[k][i]);
                    }
                }
            }
            return maxPro;
        }
};

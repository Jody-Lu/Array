// Knapsack problem
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(1 + amount, Max);
        dp[0] = 0;

        for(int i = 0; i <= amount; i++) {
            for(int coin : coins) {
                if(coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return (dp[amount] > amount)? -1 : dp.back();
    }
};
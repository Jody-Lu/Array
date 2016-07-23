class Solution(object):
    def maxProfit(self, prices):
        days = len(prices)
        if days < 2: return 0
        buy = [-prices[0]] * (days + 1)
        sell = [0] * (days + 1)

        for i in xrange(2, days + 1):
            price = prices[i - 1]
            buy[i] = max(sell[i - 2] - price, buy[i - 1])
            sell[i] = max(buy[i - 1] + price, sell[i - 1])

        return max(buy[-1], sell[-1])

sol = Solution()
prices = [1, 2, 3, 0, 2]
print sol.maxProfit(prices)

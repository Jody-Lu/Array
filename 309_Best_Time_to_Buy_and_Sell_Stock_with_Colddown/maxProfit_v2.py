class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        days = len(prices)
        if days < 2: return 0
        buy = [0] * (days + 1)
        sell = [0] * (days + 1)
        rest = [0] * (days + 1)

        for i in xrange(2, days):
            price = prices[i - 1]
            buy[i] = max(rest[i - 1] - price, buy[i - 1])
            sell[i] = max(buy[i - 1] + price, sell[i - 1])
            rest[i] = max(sell[i - 1], buy[i - 1], rest[i - 1])

        print buy
        print sell
        print rest
        return max(buy[-2], sell[-2], rest[-2])

sol = Solution()
prices = [1, 2, 3, 0, 2]
print prices
print sol.maxProfit(prices)




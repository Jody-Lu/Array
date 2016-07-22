class Solution(object):
    def maxProfit(self, prices):
        days = len(prices)

        res = 0

        for i in xrange(1, days):
            diff = prices[i] - prices[i - 1]
            if diff > 0:
                res += diff
        return res

sol = Solution()
prices = [1, 2, 3, 0, 2, 4, 5, 1]
print sol.maxProfit(prices)


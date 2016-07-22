class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        :profit[i]: max profit till the i-th day
        """
        days = len(prices)
        profit = [0] * (days + 1)
        if days <= 1: return 0
        
        for i in xrange(2, days + 1):
            #print i
            profit[i] = max(max([prices[i - 1] - prices[j] for j in xrange(i)]), profit[i -1])
                
                #profit[i] = max(profit[i - 1], prices[i - 1] - prices[j])
        
        print profit
        return profit[days]


sol = Solution()
prices = [1, 2, 3, 0, 2]
print sol.maxProfit(prices)

            




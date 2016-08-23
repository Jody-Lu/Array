class Solution(object):
    def coinChange(self, coins, amount):
        INF = 0xffffffff
        dp = [0] + [INF] * amount
        for i in xrange(amount + 1):
            for coin in coins:
                if i + coin <= amount:
                    dp[i + coin] = min(dp[i + coin], dp[i] + 1)
        
        return dp[-1] if dp[-1] != INF else -1
    
    def coinChange_v2(self, coins, amount):

        # Return the value of minimum number of first i coin needed
        # to compute amount j
        def bestvalue(i, j):
            if i == 0: return 0
            coin = coins[i - 1]
            print coin
            if coin <= j:
                return min(bestvalue(i - 1, j), bestvalue(i - 1, j - coin) + 1)
            else:
                return bestvalue(i - 1, j)
        
        return bestvalue(len(coins), amount) 

    """
    def coinChange(self, coins, amount):
        count = 0
        for coin in sorted(coins)[::-1]:
            while coin <= amount:
                print coin, amount
                amount -= coin
                count += 1
        print amount
        return -1 if amount else count
    """

sol = Solution()
#coins = [84,457,478,309,350,349,422,469,100,432,188]
coins = [370,417,408,156,143,434,168,83,177,280,117]
print coins
#amount = 6249
amount = 9953
print sol.coinChange(coins, amount)


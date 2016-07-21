class Solution(object):
    f = 
    def climbStairs(self, n):
        if n < 2: return 1
        return self.climbStairs(n-1) + self.climbStairs(n-2)

sol = Solution()
n = 3
print sol.climbStairs(100)

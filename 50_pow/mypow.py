class Solution(object):
    def myPow(self, x, n):
        def mypow(x, n):
            if n == 0: return 1.0
            val = self.myPow(x, n/2)
            return val * val if n % 2 == 0 else x * val * val
        
        return mypow(x, n) if n >= 0 else 1.0 / mypow(x, -n)

sol = Solution()
x = 1
n = 0
print sol.myPow(x, n)

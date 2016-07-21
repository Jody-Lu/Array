import time
class Solution(object):
    def countNumberWithUniqueDigits(self, n):
        if n == 0 or n == 1: return 10 ** n
        f = {1:10, 2:81}
        for i in xrange(3, n+1):
            f[i] = f[i-1] * (11 - i)
        return sum(f.values())

sol = Solution()
n = 0
start = time.time()
print sol.countNumberWithUniqueDigits(n)
print time.time() - start

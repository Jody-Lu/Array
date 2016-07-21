import time
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        f = [n] * (n + 1)

        idx = 0
        while idx * idx <= n:
            f[idx * idx] = 1
            idx += 1
        
        for i in xrange(1, n + 1):
            j = 1
            while i + j * j <= n:
                tmp = i + j * j
                f[tmp] = min(f[i] + 1, f[tmp])
                j += 1
        return f[n]

sol = Solution()
n = 9975
start = time.time()
print sol.numSquares(n)
print time.time() - start

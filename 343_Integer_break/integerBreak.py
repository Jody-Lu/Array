class Solution(object):
    def integerBreak(self, n):
        """
        Bottom up
        """
        f = [0] * (n + 1)
        for i in xrange(2, len(f)):
            for j in xrange(1, i):
                f[i] = max(f[i], (i - j) * j, f[i - j] * j)

        return f[n]

sol = Solution()
n = 58
print sol.integerBreak(n)



class Solution(object):
    def integerReplacement(self, n):
        if n == 1: return 0

        if n % 2 == 0:
            return 1 + self.integerReplacement(n/2)
        else:
            return 1 + min(self.integerReplacement(n + 1), \
                           self.integerReplacement(n - 1))

        """
        res = 0
        while(n != 1):
            if n % 2 == 0:
                n /= 2
            else:
                n = n + 1 if ((n + 1) / 2) % 2 == 0 else n - 1
            res += 1

        return res
        """

sol = Solution()
print sol.integerReplacement(3)

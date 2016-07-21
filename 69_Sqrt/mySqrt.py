class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        res = 1
        while res * res <= x:
            res += 1

        return res - 1

sol = Solution()
x = 1191373240
print sol.mySqrt(x)
             

class Solution(object):
    def isPowerOfTwo(self, n):
        return n > 0 and not (n & (n-1))
        # Ex: 16 = 0b10000 (16-1) = 0b01111
        # If n != 0 and 16 & (16 - 1) == 0

sol = Solution()
print sol.isPowerOfTwo()

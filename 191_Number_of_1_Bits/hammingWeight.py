class Solution(object):
    def hammingWeight(self, n):
        if n == 0: return 0
        else:
            return self.hammingWeight(n >> 1) + (n & 0x1)
sol = Solution()
n = 0xffffff
print sol.hammingWeight(n)

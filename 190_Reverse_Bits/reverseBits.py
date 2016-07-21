class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        bits = list(bin(n))[2:]
        while len(bits) < 32:
            bits.insert(0, '0')
        return int(''.join(bits[::-1]), 2)

sol = Solution()
n = 0
print sol.reverseBits(n)



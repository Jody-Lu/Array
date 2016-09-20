class Solution(object):
    def findNthDigit(self, n):
        n -= 1
        for digits in xrange(1, 11):
            first = 10 ** (digits - 1)
            if n < (9 * first * digits):
                return int(str(first + n/digits)[n % digits])
            else:
                n -= (9 * first * digits)


sol = Solution()
n = 15
print sol.findNthDigit(n)

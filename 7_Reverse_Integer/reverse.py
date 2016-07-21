class Solution(object):
    def reverse(self, x):
        if not x: return x
        digits = []
        sign = x / abs(x)
        x = abs(x)
        while x:
            digits.append(x % 10)
            x /= 10

        res = 0
        length = len(digits)
        for idx in xrange(length):
            res += 10 ** (length - idx - 1) * digits[idx]

        return sign * res if res <= 2147483647 and res >= -2147483648 else 0

sol = Solution()
x = 1534236469
print sol.reverse(x)


class Solution(object):
    def reverse(self, x):
        res = 0
        sign = x / abs(x)
        x = abs(x)
        while x:
            res = res * 10 + x % 10
            x /= 10

        return res * sign if res <= 2147483647 and res >= -2147483648 else 0

sol = Solution()
x = -1234
print sol.reverse(x)

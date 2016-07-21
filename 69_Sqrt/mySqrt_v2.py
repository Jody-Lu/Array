class Solution(object):
    def mySqrt(self, x):
        begin, end = 1, x / 2 + 1

        while begin <= end:
            mid = (begin + end) / 2
            sq = mid * mid
            if sq == x: return mid
            if sq < x: begin = mid + 1
            else: end = mid - 1
        return end

sol = Solution()
x = 8
print sol.mySqrt(x)



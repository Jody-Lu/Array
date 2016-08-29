class Solution(object):
    def mySqrt(self, x):
        begin, end = 1, x / 2 + 1

        while begin <= end:
            mid = (begin + end) / 2
            sq = mid * mid
            if sq == x: return mid
            if sq < x: begin = mid + 1
            else: end = mid - 1
        first, last = 0.01, 0.99

        while first <= last:
            mid = (first + last) / 2
            sq = (end + mid) * (end + mid)
            if sq == x: return mid
            if sq < x: first = mid + 0.01
            else: last = mid - 0.01
        return end + last

sol = Solution()
x = 1993
print sol.mySqrt(x)



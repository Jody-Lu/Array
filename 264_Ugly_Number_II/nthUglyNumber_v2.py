from heapq import heappop, heapreplace, heappush
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        h = [(1, 1)]
        for _ in xrange(n):
            val, factor = heappop(h)
            for x in (2, 3, 5):
                if factor <= x:
                    heappush(h, (val * x, x))
        return val

sol = Solution()
print sol.nthUglyNumber(10)


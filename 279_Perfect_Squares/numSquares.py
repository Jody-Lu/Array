import time, math

class Solution(object):
    f = [0]
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        perfSquare = [v * v for v in xrange(1, int(math.sqrt(n)) + 1)]

        for i in xrange(len(self.f), n + 1):
            self.f.append(min(self.f[i - sqr] + 1 for sqr in perfSquare if sqr <= i))
        #print len(self.f)
        return self.f[n]

sol = Solution()
n = 9975
start = time.time()
print sol.numSquares(n)
print time.time() - start


import time, math
class Solution(object):
    numSquaresDP = [0]
    def numSquares(self, n):
        if len(self.numSquaresDP) <= n:
            perfectSqr = [v ** 2 for v in xrange(1, int(math.sqrt(n)) + 1)]
            
            for i in xrange(len(self.numSquaresDP), n + 1):
                self.numSquaresDP.append(min(1 + self.numSquaresDP[i - sqr] for sqr in perfectSqr if sqr <= i))

        return self.numSquaresDP[n]


sol = Solution()
n = 9975
start = time.time()
print sol.numSquares(n)
print time.time() - start


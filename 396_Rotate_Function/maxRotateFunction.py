class Solution(object):
    def rotate(self, A, p):
        for i in xrange(p):
            A[i], A[-1 - i] = A[-1 - i], A[i]

    def maxRotateFunction(self, A):
        n = len(A)
        res = 0
        for i in xrange(n):
            res = max(res, sum([idx * item for idx, item in enumerate(A)]))
            self.rotate(A, i + 1)
        return res

sol = Solution()
A = [4, 3, 2, 6]

print sol.maxRotateFunction(A)


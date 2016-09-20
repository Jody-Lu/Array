class Solution(object):
    def maxRotateFunction(self, A):
        n = len(A)
        s = sum(A)
        F = [0] * n
        F[0] = sum([idx * item for idx, item in enumerate(A)])

        for k in xrange(1, n):
            F[k] = F[k - 1] + s - n * A[n - k]

        return max(F)

sol = Solution()
A = [4, 3, 2, 6]
print sol.maxRotateFunction(A)

import math, time

class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        k -= 1
        res = []
        nums = [i for i in xrange(1, n + 1)]
        for i in xrange(1, n + 1):
            fac = math.factorial(n - i)
            index = k / fac
            k -= index * fac
            res.append(str(nums[index]))
            nums = nums[0:index] + nums[index + 1:]
        return "".join(res)

sol = Solution()
n = 9
k = 171669
start = time.time()
print sol.getPermutation(n, k)
print time.time() - start

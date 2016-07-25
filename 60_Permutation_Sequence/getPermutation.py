import time
class Solution(object):
    cnt = 0
    res = ""
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        if not n: return ""
        nums = [str(i) for i in xrange(1, n + 1)]

        def dfs(stack, nums):
            if self.cnt >= k: return
            if not nums:
                self.cnt += 1
                if self.cnt < k:
                    return
                else:
                    self.res = ''.join(stack)

            for idx, num in enumerate(nums):
                dfs(stack + [num], nums[:idx] + nums[idx + 1:])

        dfs([], nums)
        return self.res

sol = Solution()
n = 9
k = 171669
start = time.time()
print sol.getPermutation(n, k)
print time.time() - start

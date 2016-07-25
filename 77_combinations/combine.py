class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        result = []

        def dfs(stack, num, k):
            if k == 0:
                result.append(stack)
                return

            for i in reversed(xrange(1, num + 1)):
                # Since k > num, we don't have enough num to fill --> return
                if k > i: break
                dfs(stack + [i], i - 1, k - 1)

        dfs([], n, k)
        return result

import time
sol = Solution()
n = 20
k = 16
start = time.time()
print sol.combine(n, k)
print time.time() - start

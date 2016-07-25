class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        if not k: return [[]]
        return [pre + [i] for i in xrange(1, n + 1) for pre in self.combine(i - 1, k - 1)]  

import time
sol = Solution()
n = 20
k = 16
start = time.time()
print sol.combine(n, k)
print time.time() - start


class Solution(object):
    res = []
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        self.nums = nums
        length = len(self.nums)
        self.res = [0] * length
        self._merge(0, length - 1)
        return self.res

    def _merge(self, begin, end):
        mid = (begin + end) / 2
        if begin < end:
            self._merge(mid + 1, end)
            self._merge(begin, mid)
        else:
            return
        print begin, end
        for i in reversed(xrange(begin, mid + 1)):
            for j in xrange(mid + 1, end + 1):
                if self.nums[i] > self.nums[j]:
                    self.res[i] += 1
import time
sol = Solution()
nums = [2, 0, 1, 3] #[i for i in reversed(xrange(10000))]
start = time.time()
print sol.countSmaller(nums)
print time.time() - start

from heapq import heappush, heappop, heapify
class Solution(object):
    def findKthLargest(self, nums, target):
        heapify(nums)
        for _ in xrange(len(nums) - target):
            heappop(nums)

        return nums[0]



sol = Solution()
nums = [3,2,1,5,6,4]
target = 1
print sol.findKthLargest(nums, target)


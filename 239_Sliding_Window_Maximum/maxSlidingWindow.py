class Solution(object):
    def maxSlidingWindow(self, nums, k):
        res = []
        idx = 0
        while(idx + k < len(nums)):
            res.append(max(nums[idx:idx + k]))
            idx += 1
        return res

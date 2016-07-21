class Solution(object):
    def rob(self, nums):
        if not nums: return 0
        length = len(nums)
        if length == 1: return nums[0]
        money = [None] * length
        money[0] = nums[0]
        money[1] = max(money[0], nums[1])

        for i in xrange(2, length):
            money[i] = max(nums[i] + money[i-2], money[i-1])

        return money[-1]

sol = Solution()
nums = [2, 1, 3, 4]
print sol.rob(nums)

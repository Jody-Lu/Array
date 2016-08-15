class Solution(object):
    def twoSum(self, nums, target):
        res = []
        mapping = {num:i for i, num in enumerate(nums)}
        for idx, num in enumerate(nums):
            tmp = target - num
            if tmp in mapping and idx != mapping[tmp]:
                return [idx, mapping[tmp]]

sol = Solution()
nums = [2, 7, 11, 15]
target = 9
print sol.twoSum(nums, target)

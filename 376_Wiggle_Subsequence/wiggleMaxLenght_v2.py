class Solution(object):
    def wiggleMaxLength(self, nums):
        length = len(nums)
        if length <= 2: return length
        diff = []
        diff.append(nums[1] > nums[0])
        # count the diff between nums[i] and nums[i - 1]
        for i in xrange(2, length):
            if nums[i] == nums[i - 1]:
                continue
            tmp = nums[i] > nums[i - 1]
            if tmp ^ diff[-1]:
                diff.append(nums[i] > nums[i - 1])
        return len(diff) + 1

sol = Solution()
nums = [1,17,5,10,13,15,10,5,16,8]
print sol.wiggleMaxLength(nums)

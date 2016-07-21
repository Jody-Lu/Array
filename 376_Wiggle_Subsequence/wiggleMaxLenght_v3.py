class Solution(object):
    def wiggleMaxLength(self, nums):
        length = len(nums)
        if length <= 2: return length

        top = nums[1] > nums[0]
        res = 1

        for i in xrange(2, length):
            if nums[i] == nums[i - 1]:
                continue
            tmp = nums[i] > nums[i - 1]
            if top ^ tmp:
                res += 1
                top = tmp
        return res + 1
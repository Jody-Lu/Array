class Solution(object):
    def wiggleMaxLength(self, nums):
        length = len(nums)
        if length <= 1: return length

        tops = [True, False]
        res = 0

        # Update for different top (True or False)
        # Different top has different results.
        for top in tops:
            tmp_res = 0
            for i in xrange(1, length):
                if nums[i] == nums[i - 1]:
                    continue
                tmp = nums[i] > nums[i - 1]
                if top ^ tmp:
                    tmp_res += 1
                    top = tmp

            res = max(res, tmp_res)

        return res + 1

sol = Solution()
nums = [102,101,20,91,156,78,75,142,69,81,46,142,113,163,190,178,13,36,134,54]
print sol.wiggleMaxLength(nums)

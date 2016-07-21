class Solution(object):
    def lengthOfLIS(self, nums):
        if not nums or len(nums) == 1: return len(nums)
        f = [1] * len(nums)

        for i in xrange(1, len(nums)):
            for j in xrange(i):
                if nums[i] > nums[j]:
                    f[i] = max(f[i], f[j] + 1)

        #print f
        return max(f)

sol = Solution()
#nums = [1,3,6,7,9,4,10,5,6]
nums = [3, 100, 2, 104, 3, 4, 5, 6]
#nums = [3, 100, 2, 104]
print nums
print sol.lengthOfLIS(nums)



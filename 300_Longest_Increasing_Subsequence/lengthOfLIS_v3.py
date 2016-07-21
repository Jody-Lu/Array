import bisect
class Solution(object):
    def lengthOfLIS(self, nums):
        if not nums: return 0
        f = [nums[0]]

        for i in xrange(1, len(nums)):
            if nums[i] > f[-1]: f.append(nums[i])
            else:
                pos = bisect.bisect_left(f, nums[i])
                f[pos] = nums[i]
        return len(f)


sol = Solution()
nums = [1,3,6,7,9,4,10,5,6]
#nums = [6, 3, 5, 10 , 11, 2, 9, 1, 13, 7, 4, 8, 12]
#nums = [3, 100, 2, 104]
print nums
print sol.lengthOfLIS(nums)

class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        mid = len(nums) / 2
        i = 0
        print nums
        while (mid + 1) < len(nums):
            nums[i + 1], nums[mid + 1] = nums[mid + 1], nums[i + 1]
            i += 2
            mid += 2
        """
        This method only adjust to list with differnet elements.
        nums.sort()
        for i in xrange(2, len(nums), 2):
            nums[i], nums[i - 1] = nums[i - 1], nums[i]
        """
    
sol = Solution()
nums = [1, 3, 2, 2, 3, 1]
sol.wiggleSort(nums)
print nums

class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        nums[:] = [nums[i] for i in range(0, len(nums)) if nums[i] != val]
        return len(nums)



if __name__ == '__main__':
    sol = Solution()
    val = 1
    nums = [1, 1, 2, 4, 5, 1, 2]
    result = sol.removeElement(nums, val)
    print nums, "&", result

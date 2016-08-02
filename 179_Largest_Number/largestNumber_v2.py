class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: string
        """
        nums = [str(num) for num in nums]
        nums.sort(cmp=lambda x, y: cmp(x + y, y + x))
        return ''.join(nums[::-1])

sol = Solution()
nums = [3, 30, 34, 5, 9]
sol.largestNumber(nums)

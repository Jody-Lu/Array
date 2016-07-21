import copy
class Solution(object):
    def rotate(self, nums, k):
    	"""
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        #temp = nums[-k % len(nums):] + nums[:-k % len(nums)]

        nums[:] = nums[-k % len(nums):] + nums[:-k % len(nums)]

if __name__ == '__main__':
    sol = Solution()
    k = 3
    nums = [1, 2, 3, 4, 5]
    print nums
    sol.rotate(nums, k)
    print nums

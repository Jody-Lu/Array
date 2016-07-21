class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        temp = nums[:]
        if len(nums) == 1:
            return
        while k >= len(nums):
            k -= len(nums)

        for i in range(0, k):
            nums[i] = temp[len(nums) - k + i]

        for i in range(0, len(nums) - k):
            nums[k + i] = temp[i]



if __name__ == '__main__':
    sol = Solution()
    a = 4
    num = [1, 2, 3, 4, 5, 6]
    print num
    sol.rotate(num, a)
    print num

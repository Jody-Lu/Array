class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtypr void Do not return anything, modify nums in-place instead
        """
        if len(nums) == 0: return
        
        reds = nums.count(0)
        whites = nums.count(1)
        blues = nums.count(2)

        for idx in range(reds):
            nums[idx] = 0
        
        for idx in range(whites):
            nums[idx + reds] = 1

        for idx in range(blues):
            nums[idx + reds + whites] = 2

    def swap(self, a, b):
        a, b = b, a

    def sortColors_v2(self, nums):
        second = len(nums) - 1
        zero = 0
        for i in range(second + 1):
            while nums[i] == 2 and i < second: 
                nums[i], nums[second] = nums[second], nums[i]
                second -= 1
            while nums[i] == 0 and i > zero:
                nums[i], nums[zero] = nums[zero], nums[i]
                zero += 1




if __name__ == '__main__':
    sol = Solution()
    nums = [1, 0, 2, 1, 0, 1, 0, 2]
    sol.sortColors_v2(nums)
    print nums


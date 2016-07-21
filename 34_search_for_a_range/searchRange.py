class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype List[int]
        """
        if target not in nums:
            return [-1, -1]
        start = 0
        end = len(nums) - 1
        while True:
            pin = (start + end) / 2
            if nums[pin] == target:
                break

            if nums[pin] < target:
                start = pin + 1
            else:
                end = pin - 1
        
        forward = pin
        backward = pin
        
        while forward < len(nums)  and nums[forward] == target:
            forward += 1
        else:
            forward -= 1
        while backward >= 0 and nums[backward] == target:
            backward -= 1
        else:
            backward += 1
        
        return [backward, forward]




if __name__ == '__main__':
    sol = Solution()
    nums = [5, 7, 7, 7, 7, 8, 8, 8, 10]
    target = 9
    print sol.searchRange(nums, target)

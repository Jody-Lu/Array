class Solution(object):
    def searchInsert(self, nums, target):
        if target in nums:
            return nums.index(target)
        else:
            nums.append(target)
            nums = sorted(nums) 
            return nums.index(target)
    
    def searchInsert_v2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int 
        """
        start = 0
        end = len(nums) - 1

        while start <= end:
            pin = (start + end) / 2
            #print start, end
            if nums[pin] == target: return pin
            
            if nums[pin] > target:
                end = pin - 1
            else:
                start = pin + 1

        if nums[pin] > target:
            pass


if __name__ == '__main__':
    sol = Solution()
    nums = [1, 3, 5 ,7]
    target = 8
    print sol.searchInsert(nums, target)



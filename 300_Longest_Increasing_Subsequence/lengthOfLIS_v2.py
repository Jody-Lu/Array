class Solution(object):
    def lengthOfLIS(self, nums):
        if not nums: return 0
        f = [nums[0]]

        for i in xrange(1, len(nums)):
            # If nums[i] > the end of f, append nums[i] to f. 
            if nums[i] > f[-1]: f.append(nums[i])
            else:
                # binary search
                begin, end = 0, len(f) 
                while begin < end:
                    mid = (begin + end) / 2
                    if nums[i] == f[mid]:
                        begin = mid
                        break
                    if nums[i] > f[mid]:
                        begin = mid + 1
                    else: end = mid
                # replace f[begin] with nums[i] 
                f[begin] = nums[i]
        return len(f)

def binary_search(nums, target):
    begin, end = 0, len(nums)
    while begin < end:
        mid = (begin + end) / 2
        if nums[mid] == target: return mid
        if target > nums[mid]:
            begin = mid + 1
        else: 
            end = mid
    
    return begin

nums = [2, 100, 104]
target = 102
print binary_search(nums, target)

sol = Solution()
#nums = [1,3,6,7,9,4,10,5,6]
nums = [6, 3, 5, 10 , 11, 2, 9, 1, 13, 7, 4, 8, 12]
#nums = [3, 100, 2, 104]
print nums
print sol.lengthOfLIS(nums)

"""
Version 1: TLE (DP)
"""
class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.nums = nums
        self.sums = [0] * (len(nums) + 1) #[)
        for i in xrange(len(self.nums)):
            self.sums[i + 1] = self.sums[i] + self.nums[i]

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: int
        """
        for j in xrange(i + 1, len(self.sums)):
            self.sums[j] -= self.nums[i]
            self.sums[j] += val
        self.nums[i] = val

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j + 1] - self.sums[i]

nums = [7, 2, 7, 2, 0]
print nums
na = NumArray(nums)
print na.sums
na.update(4, 6)
print na.nums
print na.sums 
na.update(0, 2)
na.update(0, 9)
print na.nums 
print na.sums 
#print na.sumRange(4, 4)
na.update(3, 8)
print na.sums
print na.sumRange(0, 4)

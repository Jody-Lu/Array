class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        # sums[i]: sum of 0th to (i - 1)th elements 
        n_length = len(nums) + 1
        self.sums = [0] * n_length
        for i in xrange(1, n_length):
            self.sums[i] = self.sums[i - 1] + nums[i - 1]
        print self.sums
            
    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j + 1] - self.sums[i]

        

nums = [1, 2, 3]
print nums
numArray = NumArray(nums) 
print numArray.sumRange(0 , 1)

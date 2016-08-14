class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.size = len(nums)
        self.BITTree = [0] * (len(nums) + 1)
        for i in xrange(self.size):
            self.updatebit(i, nums[i])

    def updatebit(self, i, val):
        i += 1
        while i <= self.size:
            self.BITTree[i] += val
            i += i & (-i)

    def getSum(self, i):
        sum = 0
        i += 1
        while i > 0:
            sum += self.BITTree[i]
            i -= i & (-i)
        return sum

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.getSum(j) - self.getSum(i - 1)

nums = [-2, 0, 3, -5, 2, -1]
na = NumArray(nums)
print na.sumRange(0, 5)

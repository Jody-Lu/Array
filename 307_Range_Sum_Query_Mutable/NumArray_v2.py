class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.size = len(nums)
        self.nums = nums
        self.BITTree = [0] * (self.size + 1)
        # construct BIT (Binary Indexed Tree)
        def construct(arr, n):
            for i in xrange(n):
                self.updatebit(i, nums[i])
                print self.BITTreesw
        construct(nums, self.size)


    def updatebit(self, i, val):
        i += 1

        while i <= self.size:
            print i
            self.BITTree[i] += val
            i += i & (-i)

    def update(self, i, val):
        self.updatebit(i, val - self.nums[i])
        self.nums[i] = val

    def getSum(self, i):
        s = 0
        i += 1
        while i > 0:
            s += self.BITTree[i]
            i -= i & (-i)
        return s

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.getSum(j) - self.getSum(i - 1)


nums = [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9]
na = NumArray(nums)
print na.BITTree

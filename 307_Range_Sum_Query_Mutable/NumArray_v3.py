from math import ceil, log
class SegmentTree(object):
    def __init__(self, arr):
        """
        max_size: maximum segment tree's size
        SegTree: list for storing tree's element
        """
        self.size = len(arr)
        self.arr = arr
        x = int(ceil(log(self.size) / log(2)))
        self.max_size = 2 * int(2 ** x) - 1
        self.SegTree = [None] * self.max_size
        self.constructTreeUtil(0, self.size-1, 0)

    def updateValue(self, i, val):
        diff = val - self.arr[i]
        self.arr[i] = val
        self.updateValueUtil(0, self.size-1, i, diff, 0)

    def getSum(self, i, j):
        return self.getSumUtil(0, self.size-1, i, j, 0)

    def updateValueUtil(self, ss, se, i, diff, si):
        if i < ss or i > se:
            return

        self.SegTree[si] += diff
        if ss != se:
            mid = (ss + se) / 2
            self.updateValueUtil(ss, mid, i, diff, si*2+1)
            self.updateValueUtil(mid+1, se, i, diff, si*2+2)


    def getSumUtil(self, ss, se, qs, qe, si):
        # If segment of this node is a part of given query range,
        # then return the sum of the segment
        # We can understand by thinking that each node's value is
        # the RangeSum
        if qs <= ss and qe >= se:
            return self.SegTree[si]

        if qs > se or qe < ss:
            return 0

        mid = (ss + se) / 2

        return self.getSumUtil(ss, mid, qs, qe, si*2 + 1) + \
               self.getSumUtil(mid+1, se, qs, qe, si*2 + 2)


    def constructTreeUtil(self, ss, se, si):
        """
        si: current node at SegTree
        ss: start of self.arr
        se: end of self.arr
        """
        # ``ss == se``: there is one element in the array
        if ss == se:
            self.SegTree[si] = self.arr[ss]
            return self.arr[ss]

        mid = (ss + se) / 2
        self.SegTree[si] = self.constructTreeUtil(ss, mid, si*2+1) + \
                           self.constructTreeUtil(mid+1, se, si*2+2)

        return self.SegTree[si] 
"""
arr = [1, 2]
st = SegmentTree(arr)
print st.SegTree
print st.getSum(0, 1)
st.updateValue(0, 2)
print st.getSum(0, 1)
print st.arr
"""

class NumArray(object):
    def __init__(self, nums):
        self.st = SegmentTree(nums)

    def update(self, i, val):
        self.st.updateValue(i, val)

    def sumRange(self, i, j):
        return self.st.getSum(i, j)

nums = [1, 2]
na = NumArray(nums)
print na.sumRange(0, 1)
na.update(0, 2)
print na.sumRange(0, 1)

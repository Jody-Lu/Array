from math import log, ceil
class SegmentTree(object):
    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        n = len(arr)
        x = int(ceil(log(n) / log(2)))
        self.arr = arr
        self.size = n
        self.max_size = 2 * int(2 ** x) - 1
        self.st = [None] * self.max_size
        self.constructSTUtil(0, self.size-1, 0)

    def constructSTUtil(self, ss, se, si):
        """
        arr: input array
        ss: segment start -> st[0]
        se: segment end   -> st[-1]
        st: segment tree
        si: index points to current position at `st`
        """
        if ss == se:
            self.st[si] = self.arr[ss]
            return arr[ss]
        
        mid = (ss + se) / 2
        self.st[si] = self.constructSTUtil(ss, mid, si*2+1) + \
                 self.constructSTUtil(mid+1, se, si*2+2)
        return self.st[si]

    def getSum(self, qs, qe):
        """
        qs: query start
        qe: query end
        """
        return self.getSumUtil(0, self.size - 1, qs, qe, 0)

    def getSumUtil(self, ss, se, qs, qe, si):
        """
        ss & se --> Starting and ending indexes of the segment 
        represented by current node, i.e., st[si]
        """
        if qs <= ss and qe >= se:
            return self.st[si]
        
        if se < qs or ss > qe:
            return 0

        mid = (ss + se) / 2
        return self.getSumUtil(ss, mid, qs, qe, 2*si+1) + \
               self.getSumUtil(mid+1, se, qs, qe, 2*si+2)
    
    def updateValue(self, i, val):
        diff = val - self.arr[i]
        self.arr[i] = val
        self.updateValueUtil(0, self.size-1, i, diff, 0)
        
    def updateValueUtil(self, ss, se, i, diff, si):
        if i < ss or i > se:
            return
        
        self.st[si] += diff
        if se != ss:
            mid = (ss + se) / 2
            self.updateValueUtil(ss, mid, i, diff, 2*si+1)
            self.updateValueUtil(mid+1, se, i, diff, 2*si+2)


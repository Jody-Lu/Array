class Solution(object):
    # Bottom-Up
    aux = []
    def mergeSortBU(self, nums):
        sz = 1
        N = len(nums)
        self.aux = [None] * N
        while sz < N:
            lo = 0
            while lo < N - sz:
                self.merge(nums, lo, lo + sz - 1, min(lo+sz+sz-1, N-1))
                lo += (sz + sz)
            sz = sz + sz
    
    def merge(self, nums, lo, mid, hi):
        for i in xrange(lo, hi + 1):
            self.aux[i] = nums[i]
        
        i = lo
        j = mid + 1
        for k in xrange(lo, hi + 1):
            if i > mid: 
                nums[k] = self.aux[j]
                j += 1
            elif j > hi:
                nums[k] = self.aux[i]
                i += 1
            elif self.aux[j] < self.aux[i]:
                nums[k] = self.aux[j]
                j += 1
            else:
                nums[k] = self.aux[i]
                i += 1
        
    
    # Top-Down
    def mergeSort(self, nums):
        self._mergeSort(nums, 0, len(nums) - 1)

    def _mergeSort(self, aList, first, last):
        mid = (first + last) / 2
        if first < last:
            self._mergeSort(aList, first, mid)
            self._mergeSort(aList, mid+1, last)
        else:
            return

        # a: tmp array idx, f: first array idx, l: second array idx
        a, f, l = 0, first, mid + 1
        # tmp array storing the sorted array
        tmp = [None] * (last - first + 1)

        # merge pieces
        while f <= mid and l <= last:
            tmp[a] = min(aList[f], aList[l])
            if aList[f] < aList[l]: f += 1 
            else: l += 1
            a += 1
        # since we may have some remaining items in the 
        # we have to make it
        if f <= mid: tmp[a:] = aList[f:mid+1]
        if l <= last: tmp[a:] = aList[l:last+1]
        # write back to the list 
        if tmp != aList[first:last+1]:
            aList[first:last+1] = tmp[:]

if __name__ == '__main__':
    import time
    nums = [i for i in reversed(xrange(1000000))]
    sol = Solution()
    start = time.time()
    sol.mergeSortBU(nums)
    print time.time() - start
    nums = [i for i in reversed(xrange(1000000))]
    start = time.time()
    sol.mergeSort(nums)
    print time.time() - start

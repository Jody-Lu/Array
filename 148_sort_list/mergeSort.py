class Solution(object):
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
    nums = [8, 5, 3, 1, 9, 6, 0, 7, 100, 4, 2, 5]
    sol = Solution()
    sol.mergeSort(nums)
    print nums

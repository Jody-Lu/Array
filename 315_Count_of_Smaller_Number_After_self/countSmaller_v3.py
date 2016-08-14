class Solution(object):
    greater = {}
    def countSmaller(self, nums):
        self.greater = {i:0 for i in nums}
        self.nums = nums[:]
        res = [0] * len(nums)
        self._mergeSort(nums, 0, len(nums) - 1)
        for i in xrange(len(nums)):
            res[i] = self.greater[self.nums[i]]

        return res


    def _mergeSort(self, nums, first, last):
        mid = (first + last) / 2
        if last > first:
            self._mergeSort(nums, first, mid)
            self._mergeSort(nums, mid + 1, last)
            self.merge(nums, first, last, mid + 1)


    def merge(self, nums, first, last, mid):
        a, f, l = 0, first, mid
        tmp = [None] * (last - first + 1)

        while f <= mid - 1 and l <= last:
            if nums[f] <= nums[l]:
                tmp[a] = nums[f]
                self.greater[f] += 1
                f += 1
            else:
                tmp[a] = nums[l]
                l += 1
            a += 1

        if f <= mid - 1:
            tmp[a:] = nums[f:mid]


        if l <= last:
            tmp[a:] = nums[l:last + 1]

        a = 0
        while first <= last:
            nums[first] = tmp[a]
            first += 1
            a += 1

sol = Solution()
#nums = [i for i in reversed(xrange(11))]
nums = [26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13]
print nums
print sol.countSmaller(nums)

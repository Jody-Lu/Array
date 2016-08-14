class Solution(object):
    def countSmaller(self, nums):
        self.greater = [0] * len(nums)
        self._mergeSort(nums, 0, len(nums) - 1)
    
    def _mergeSort(self, nums, first, last):
        mid = (first + last) / 2
        if first < last:
            self._mergeSort(nums, first, mid)
            self._mergeSort(nums, mid + 1, last)
            self.merge(nums, first, mid, last)

    def merge(self, nums, Lpos, Lend, Rend):
        Rpos = Lend + 1
        Tpos = Lpos
        n = Rend - Lpos + 1
        t = Rpos
        tmp = [None] * n

        while Lpos <= Lend and Rpos <= Rend:
            if nums[Lpos] <= nums[Rpos]:
                tmp[Tpos] = nums[Lpos]
                self.greater[Tpos] += Rpos - t
                Lpos += 1
            else:
                print Tpos, Rpos
                tmp[Tpos] = nums[Rpos]
                Rpos += 1
            Tpos += 1

        while Lpos <= Lend:
            tmp[Tpos] = nums[Lpos]
            self.greater[Tpos] += Rpos - t
            Tpos += 1
            Lpos += 1

        while Rpos <= Rend:
            tmp[Tpos] = nums[Rpos]
            Tpos += 1
            Rpos += 1

        for i in xrange(n):
            nums[i] = tmp[i]

sol = Solution()
nums = [5, 2, 6, 1]#[26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41]
sol.countSmaller(nums)

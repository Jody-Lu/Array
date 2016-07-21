class Solution(object):
    def findKthLargest(self, nums, target):
        self.target = target
        self.nums = nums
        return self.quickSelect(0, len(nums) - 1)

    def quickSelect(self, p, r):
        if p == r: 
            return self.nums[p]
        q = self.partition(p, r)
        if q == self.target - 1:
            return self.nums[q]
        if q > self.target - 1:
            return self.quickSelect(p, q - 1)
        else:
            return self.quickSelect(q + 1, r)

    def partition(self, begin, end):
        left = begin + 1
        right = end
        pivot = nums[begin]

        while True:
            while left <= right and self.nums[left] >= pivot:
                left += 1
            while right >= left and self.nums[right] <= pivot:
                right -= 1

            if left <= right:
                self.nums[right], self.nums[left] = self.nums[left], self.nums[right]
            else:
                break

        self.nums[begin], self.nums[right] = self.nums[right], self.nums[begin]
        return right

sol = Solution()
nums = [3,2,1,5,6,4]
target = 3
print [sol.findKthLargest(nums, target) for target in range(1, 4)] 

import time
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums = [str(i) for i in xrange(1, n + 1)]
        for i in xrange(k):
            self.nextPermutation(nums)
        return ''.join(nums)

    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        index = length - 1
        while nums[index - 1] >= nums[index] and index:
            index -= 1

        if not index:
            nums.sort()
            return

        j = length - 1
        while j >= index - 1:
            if nums[j] > nums[index - 1]:
                nums[j], nums[index - 1] = nums[index - 1], nums[j]
                nums[index:] = sorted(nums[index:])
                break
            else:
                j -= 1

sol = Solution()
n = 9
k = 171669
start = time.time()
print sol.getPermutation(n, k)
print time.time() - start

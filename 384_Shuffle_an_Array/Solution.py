import random

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.origNums = nums[:]
        self.shufNums = nums[:]
        self.N = len(nums)



    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        self.shufNums = self.origNums[:]
        return self.origNums


    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        for i in xrange(self.N):
            r = random.randint(0, i)
            self.shufNums[i], self.shufNums[r] = self.shufNums[r], self.shufNums[i]

        return self.shufNums

nums = [1, 2, 3, 4, 5]
sol = Solution(nums)
print sol.shuffle()
print sol.reset()
print sol.shuffle()


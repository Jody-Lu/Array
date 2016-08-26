class Solution(object):
    def singleNumber(self, nums):
        counts = {}
        for idx, num in enumerate(nums):
            if num in counts:
                counts[num] += 1
            else:
                counts[num] = 1

        for key in counts:
            if counts[key] == 1:
                return key

        

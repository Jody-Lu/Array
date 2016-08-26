class Solution(object):
    def singleNumber(self, nums):
        counts = {}
        res = []
        for n in nums:
            if n not in counts:
                counts[n] = 1
            else:
                counts[n] += 1
        for key in counts:
            if counts[key] == 1:
                res.append(key)

        return res

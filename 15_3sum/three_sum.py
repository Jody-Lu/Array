class Solution(object):
    def threeSum(self, nums):
        res = []
        if len(nums) < 3: 
            return res

        nums.sort()
        target = 0
        last = len(nums) - 1
        for idx in xrange(0, len(nums) - 2):
            j = i + 1
            if i > 0 and nums[i] == nums[i - 1]:
                continue;
            k = last
            while(j < k):
                if nums[i] + nums[j] + nums[k] < target:
                    j += 1
                    while nums[j] == nums[j - 1] and j < k:
                        j += 1
                elif nums[i] + nums[j] + nums[k] > target:
                    k -= 1
                    while nums[k] == nums[k + 1] and j < k:
                        k -= 1
                else:
                    res.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while nums[j] == nums[j - 1] and nums[k] == nums[k + 1] and j < k:
                        j += 1
        return res


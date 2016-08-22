class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        last = len(nums)
        result = sum(nums[last-3:])
        if len(nums) < 3: return result
        if len(nums) == 3: return sum(nums)
        remain = abs(target - sum(nums[last-3:]))

        for i in xrange(0, last - 2):
            j = i + 1
            k = last - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s == target:
                    return s
                if abs(s - target) <= remain:
                    remain = abs(s - target)
                    result = s
                    if s - target < 0:
                        j += 1
                    else:
                        k -= 1
                else:
                    if(abs(target - (nums[i] + nums[j+1] + nums[k])) > abs(target - (nums[i] + nums[j] + nums[k-1]))):
                        k -= 1
                    else:
                        j += 1
        return result

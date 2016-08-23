class Solution(object):
    def fourSum(self, nums, target):
        res = []
        cache = {nums[i]+nums[j]:[] for i in xrange(len(nums)) for j in xrange(i+1, len(nums))}
        for i in xrange(len(nums)):
            for j in xrange(i+1, len(nums)):
                cache[nums[i] + nums[j]].append((i, j))

        for c in xrange(len(nums)):
            for d in xrange(c+1, len(nums)):
                key = target - (nums[c] + nums[d])
                if key not in cache:
                    continue
                vec = cache[key]
                for v in vec:
                    if c <= v[1]:
                        continue
                    res.append([nums[v[0]], nums[v[1]], nums[c], nums[d]])
        return res



sol = Solution()
nums = [1, 0, -1, 0, -2, 2]
target = 0
print sol.fourSum(nums, target)


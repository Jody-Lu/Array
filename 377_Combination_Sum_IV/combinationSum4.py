class Solution(object):
    def combinationSum4(self, nums, target):
        self.res = 0
        nums.sort()
        def dfs(nums, remain):
            if not remain:
                self.res += 1
            for num in nums:
                if num > remain: return 
                dfs(nums, remain - num)

        dfs(nums, target)
        return self.res

sol = Solution()
nums = [4, 2, 1]
target = 32
print sol.combinationSum4(nums, target)

class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        nums.sort()

        def dfs(stack, nums):
            if not nums:
                if stack not in result:
                    result.append(stack)
                return

            for idx, num in enumerate(nums):
                if idx and nums[idx] == nums[idx - 1]: continue
                dfs(stack + [num], nums[:idx] + nums[idx + 1:])

        dfs([], nums)
        return result

sol = Solution()
nums = [1,1,0,0,1,-1,-1,1]
print sol.permuteUnique(nums)

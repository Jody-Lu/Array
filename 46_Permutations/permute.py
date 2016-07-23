class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        def dfs(stack, nums):
            if not nums:
                res.append(stack)
                return

            for idx, num in enumerate(nums):
                dfs(stack + [num], nums[0:idx] + nums[idx + 1:])

        dfs([], nums)
        return res

sol = Solution()
nums = [1, 2]
print sol.permute(nums)

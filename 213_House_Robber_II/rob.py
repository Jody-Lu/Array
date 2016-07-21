class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        dp[i]: At house i, the max money the robber can rob.
        """
        def bestValue(nums):
            if not nums: return 0
            length = len(nums)
            if length <= 2: return max(nums)
            dp = [0] * length
            dp[0] = nums[0]
            dp[1] = max(nums[0], nums[1])
            
            for i in xrange(2, length - 1):
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])

            end = length - 1
            dp[end] = max(nums[end] + dp[end - 2] - dp[0], dp[end - 1])
            return dp[-1]
        
        return max(bestValue(nums), bestValue(nums[::-1]))


sol = Solution()
nums = [1, 2, 1, 1]
print nums
print sol.rob(nums[::-1])



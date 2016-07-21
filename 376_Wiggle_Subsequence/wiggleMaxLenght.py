class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        longest subsequence that is a wiggle sequence.
        """
        length = len(nums)
        if length <= 2: return length

        # dp[i]: the max subsequence until element i
        dp = [0] * length
        dp[0], dp[1]= 1, 2

        for i in xrange(2, length):
            if nums[i] == nums[i - 1]:
                dp[i] = dp[i - 1]

            if nums[i] < nums[i - 1]:
                tmp = i - 1
                while nums[tmp] < nums[tmp - 1]:
                    tmp -= 1
                dp[i] = dp[tmp] + 1
                print "tmp:", dp[tmp]
            else:
                tmp = i - 1
                while nums[tmp] > nums[tmp - 1]:
                    tmp -= 1
                dp[i] = dp[tmp] + 1
        print dp
        return dp[length - 1]

sol = Solution()
nums = [1,17,5,10,13,15,10,5,16,8]
print nums
print sol.wiggleMaxLength(nums)




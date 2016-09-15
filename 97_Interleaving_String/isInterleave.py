class Solution(object):
    def isInterleave(self, s1, s2, s3):
        if not s1 or  not s2 or  not s3:
            return True

        if not s3:
            return False

        return (s3[0] == s1[0] and self.isInterleave(s1[1:], s2, s3[1:])) \
                or (s3[0] == s2[0] and self.isInterleave(s1, s2[1:], s3[1:]))

sol = Solution()
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"

print sol.isInterleave(s1, s2, s3)


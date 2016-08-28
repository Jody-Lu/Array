class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        counts = {}
        for c in s:
            if c not in counts:
                counts[c] = 1
            else:
                counts[c] += 1

        for idx, c in enumerate(s):
            if counts[c] == 1:
                return idx
        return -1

sol = Solution()


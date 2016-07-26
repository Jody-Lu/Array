class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type str: List[str]
        :rtype
        """
        if not strs: return ""
        index = 0
        min_str = min(strs, key=len)

        while index < len(min_str):
            j = 1
            while j < len(strs):
                if strs[j][index] != strs[j - 1][index]:
                    break
                else:
                    j += 1

            if j < len(strs):
                break
            else:
                index += 1

        return strs[0][:index]

sol = Solution()
strs = []
print sol.longestCommonPrefix(strs)


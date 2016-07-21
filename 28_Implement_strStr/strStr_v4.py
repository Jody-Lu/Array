class Solution(object):
    def strStr(self, haystack, needle):
        n, m = len(haystack), len(needle)
        if m > n: return -1
        if not m: return 0

        for i in range(n):
            if haystack[i] == needle[0]:
                if i + m > n: 
                    break
                elif haystack[i:i + m] in needle:
                    return i
        return -1

sol = Solution()
haystack = "mississippi"
needle = "pi"

print sol.strStr(haystack, needle)

        

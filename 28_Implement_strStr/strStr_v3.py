class Solution():

    def strStr(self, haystack, needle):
        m, n = len(needle), len(haystack)
        mlast = m - 1
        
        if m > n: return -1
        
        if m == 1:
            for i in range(n):
                if haystack[i] == needle[0]:
                    return i
            return -1

        skip = self.strStr(haystack, needle[-1])
        if skip == -1: skip = m - 1
            
        #print "skip", skip
        
        for i in range(0, n - m + 1):
            if haystack[i + m - 1] == needle[m - 1]:
                if haystack[i:i + mlast] == needle[0:mlast]:
                    return i
                if haystack[i + m] not in needle:
                    i += m
                else:
                    i += skip
            else:
                if haystack[i + m] not in needle:
                    i += m
        return -1

sol = Solution()
haystack = "mississippi"
needle = "pi"

print sol.strStr(haystack, needle)







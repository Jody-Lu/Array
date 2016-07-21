class Solution(object):
    def strStr(self, haystack, needle):
        if not needle: 
            return 0
        if not haystack and needle: 
            return -1
        if len(needle) > len(haystack):
            return -1
        
        begin = forward = 0
        end = len(haystack) - 1

        while forward <= end:
            if haystack[forward] == needle[0]:
                print forward
                begin = forward
                index = 0
                while forward <= end and index < len(needle) and haystack[forward] == needle[index]:
                    index += 1
                    forward += 1
                if index == len(needle): 
                    return begin
                else:
                    if forward == len(haystack): return -1
                    else: forward = begin
            forward += 1
        
        return -1

sol = Solution()
haystack = "mississippi"
needle = "pi"
print sol.strStr(haystack, needle)



class Solution(object):
    def minWindow(self, s, t):
        dict_map = {c:-1 for c in t}
        res = s
        for idx, c in enumerate(s):
            #print dict_map, res
            if c in dict_map:
                dict_map[c] = idx
            if -1 not in dict_map.values():
                res = min(s[min(dict_map.values()):idx+1], res, key=len)
                dict_map[s[min(dict_map.values())]] = -1
            #print dict_map, res
        #print res
        return res

sol = Solution()
s = "ADOBECODEBANC"
t = "ABC"
print s
sol.minWindow(s, t)


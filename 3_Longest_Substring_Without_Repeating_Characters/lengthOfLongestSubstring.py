class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if not s: return 0
        char_dic = {}
        begin = forward = res = 0
        
        for w in s: char_dic[w] = -1
        
        for idx, w in enumerate(s):
            forward = idx
            if char_dic[w] == -1:
                char_dic[w] = idx
            else:
                res = max(res, forward - begin)
                for i in xrange(begin, char_dic[w]):
                    char_dic[s[i]] = -1
                begin = char_dic[w] + 1
                char_dic[w] = forward
        
        return max(res, forward - begin + 1)

sol = Solution()
s = 'abccdefgaaaa'
print s
print sol.lengthOfLongestSubstring(s)


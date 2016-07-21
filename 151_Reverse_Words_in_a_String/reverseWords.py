class Solution(object):
    def reverseWords(self, s):
        words = s.split(' ')
        while '' in words: words.remove('')
        return ' '.join(words[::-1])


sol = Solution()
s = '     a    b    '
print sol.reverseWords(s)

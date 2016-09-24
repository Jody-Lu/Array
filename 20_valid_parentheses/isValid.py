class Solution(object):
    def isValid(self, s):
        if len(s) % 2 == 1: return False
        stack = []
        para_dic = {')':'(', ']':'[', '}':'{'}
        for idx in xrange(len(s)):
            if s[idx] in {'(', '[', '{'}:
                stack.append(s[idx])
            else:
                if not len(stack) or para_dic[s[idx]] != stack[-1]: return False
                else: stack.pop()


        return len(stack) == 0

sol = Solution()
s = "{(})[]"
print sol.isValid(s)


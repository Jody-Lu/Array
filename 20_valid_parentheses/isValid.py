class Solution(object):
    def isValid(self, s):
        stack = []
        para_dic = {')':'(', ']':'[', '}':'{'}
        for idx in xrange(len(s)):
            if s[idx] == '(' or s[idx] == '{' or s[idx] == '[':
                stack.append(s[idx])
            else:
                if para_dic[s[idx]] != stack[-1]: return False
                else: stack.pop()

        return True

sol = Solution()
s = "{(})[]"
print sol.isValid(s)


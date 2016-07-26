class Solution(object):
    def isPalindrome(self, s):
        begin = 0
        end = len(s) - 1
        while begin < end:
            if s[begin] == s[end]:
                begin += 1
                end -= 1
            else:
                break
        if begin < end:
            return False
        else:
            return True

    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        result = []
        def dfs(stack, s):
            if not s:
                result.append(stack)

            if len(s) == 1:
                result.append(stack + [s])
                return

            i = 1
            while i <= len(s):
                if self.isPalindrome(s[:i]):
                    dfs(stack + [s[:i]], s[i:])
                i += 1
        dfs([], s)
        return result

sol = Solution()
print sol.partition("abbccc")

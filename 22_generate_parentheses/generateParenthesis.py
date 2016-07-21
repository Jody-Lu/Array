class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        def generateStr(nleft, nright, s):
            if nleft == n and nright == n:
                result.append(s)

            if nleft <= n:
                generateStr(nleft + 1, nright, s + '(')

            if nright < nleft:
                generateStr(nleft, nright + 1, s + ')')



        generateStr(0, 0, '')
        return result

sol = Solution()
n = 15
print sol.generateParenthesis(n)

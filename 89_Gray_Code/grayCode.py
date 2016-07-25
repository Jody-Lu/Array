class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = []
        if not n: return [0]
        pair = ['0', '1']

        def dfs(stack, k, pair):

            if k == 0:
                result.append(int(''.join(stack), 2))
                return

            # In each level, the first one must be [0, 1] and the second one must be [1, 0]
            for idx, i in enumerate(pair):
                if idx  == 0:
                    dfs(stack + [i], k - 1, ['0', '1'])
                else:
                    dfs(stack + [i], k - 1, ['1', '0'])

        dfs([], n, pair)
        return result

sol = Solution()
n = 0
print  sol.grayCode(n)


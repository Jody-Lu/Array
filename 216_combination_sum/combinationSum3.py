class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype List[List[int]]
        """
        result = []

        def dfs(k, n, stack, start):
            if k == len(stack):
                if n == 0:
                    result.append(stack)
                return

            for i in xrange(start, 9):
                if n < (i + 1): return
                dfs(k, n - (i + 1), stack + [i + 1], i + 1)

        dfs(k, n, [], 0)
        return result

if __name__ == '__main__':
    num = []
    sol = Solution()
    k = 3
    n = 9
    print sol.combinationSum3(k, n)
    

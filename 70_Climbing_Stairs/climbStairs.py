import time

class Solution(object):
    def climbStairs(self, n):
        """
        count[i]: #method climbs to i-th stair 
        """
        if n <= 1: return 1
        count = [None] * n
        count[0] = 1
        count[1] = 2
        for idx in xrange(2, n):
            count[idx] = count[idx-1] + count[idx-2]

        return count[-1]
    
    def climbStairsMethod(self, n):
        result = []
        tmp = []
        def dfs(method, n):
            if not n:
                result.append(method)
                return
            for step in [1, 2]:
                if step > n: break
                dfs(method + [step], n-step)
        dfs([], n)
        return result

    def climbStairsMethod_v2(self, n):
        if n == 1: return [[1]]
        if n == 2: return [[1, 1], [2]]
        current = [[1], [2]]
        result = []
        steps = [1, 2]

        while current:
            #print current
            top = current.pop()
            for step in steps:
                total = step + sum(top)
                if total > n:
                    break
                if total == n:
                    result.append(top + [step])
                    break
                current.append(top + [step])

        return result







sol = Solution()
n = 30
start = time.time()
sol.climbStairsMethod(n)
print time.time() - start
start = time.time()
sol.climbStairsMethod_v2(n)
print time.time() - start

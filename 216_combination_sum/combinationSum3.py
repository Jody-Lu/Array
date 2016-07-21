class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype List[List[int]]
        """
        result = []
        stack = []
        start = 1
        def helper(k, n, stack, start):
            if n == 0:
                if k == 0:
                    print stack, id(stack)
                    result.append(stack)
                    return 
                else:
                    return

            for i in range(start, 10):
                if n < i: return
                stack.append(i)
                helper(k-1, n-i, stack, i+1)
                #helper(k-1, n-i, stack + [i], i+1)
                stack.pop()

        helper(k, n, stack, start)
        return result
    """
    def combinationSum3(self, k, n):
        ans = []
        def search(start, cnt, sums, nums):
            if cnt > k or sums > n:
                return
            if cnt == k and sums == n:
                ans.append(nums)
                return
            for x in range(start + 1, 10):
                search(x, cnt + 1, sums + x, nums + [x])
        search(0, 0, 0, [])
        return ans
    """
if __name__ == '__main__':
    num = []
    sol = Solution()
    k = 2
    n = 10
    print sol.combinationSum3(k, n)
    
    #sol.test(num)
    #print num

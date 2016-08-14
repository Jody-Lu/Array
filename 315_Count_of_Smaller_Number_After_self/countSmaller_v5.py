class FenwickTree(object):
    def __init__(self, n):
        self.n = n
        self.sums = [0] * (n + 1)
    
    def add(self, x, val):
        while x <= self.n:
            self.sums[x] += val
            x += x & (-x)
        
    def getSum(self, x):
        s = 0
        while x > 0:
            s += self.sums[x]
            x -= x & (-x)
        return s


class Solution(object):
    def countSmaller(self, nums):
        idxes = {}
        for k, v in enumerate(sorted(nums)):
            idxes[v] = k + 1
        #print idxes
        iNums = [idxes[x] for x in nums]
        #print iNums
        ft = FenwickTree(len(iNums))
        ans = [0] * len(nums)
        for i in xrange(len(iNums) - 1, -1, -1):
            ans[i] = ft.getSum(iNums[i] - 1)
            ft.add(iNums[i], 1)
            #print "ft", ft.sums
        #print "test", ft.getSum(iNums[0])
        return ans

sol = Solution()
nums = [1, 2, 3, 4]
print sol.countSmaller(nums)

#Count of Smaller After Self

##Fenwick Tree

1. Also known as **Binary Indexed Tree**。
2. 先找出 ``nums`` 中每個元素的相對大小關係。
3. 再從最後面開始推入 ``Binary Indexed Tree``。
4. 可以這樣想，假設 ``iNums = [4, 2, 3, 1]``，先取 index 1 的 sum，再從 1 開始更新 BIT，這樣可以保證 iterate 到 index ``i`` 時，如果 ``i > 1``，則可以數到 1; 如果小於，則數不到。

```python
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
```

##Merge Sort


"""
Return # components
0: connect to dummy
"""
class UF(object):
    # p and q are connected iff they have the same id.
    id = []   # id[i] = tree  parent of i
    rank = [] # rank[i] = rank(size) of subtree rooted at i (cannot be more than 31)
    count = 0 # number of components

    def __init__(self, N):
        """
        :type N: int 
        """
        self.count = N
        self.id = [i for i in xrange(N)]
        self.rank = [0] * N

    def find(self, p):
        """
        :type p: int
        :rtype: int
        """
        while p != self.id[p]:
            self.id[p] = self.id[self.id[p]]
            p = self.id[p]
        return p

    def getCount(self):
        """
        :rtype: int
        """
        return self.count

    def connected(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype bool
        """
        return self.find(p) == self.find(q)

    def connect(self, p, q):
        """
        :type p: int
        :type q: int
        The smaller tree always goes below.
        """
        i = self.find(p) # find p's parent
        j = self.find(q) # find q's parent
        # p and q has been connected
        if i == j: 
            return
        if self.rank[i] < self.rank[j]:
            self.id[i] = j
        elif self.rank[i] > self.rank[j]:
            self.id[j] = i
        else:
            # if tree's size is equal, put the second one under the first one.
            self.id[j] = i
            # so, the first one's rank += 1
            self.rank[i] += 1
        # since union, the # component -= 1
        self.count -= 1

class Solution(object):
    def numIslands(self, grid):
        if not grid:
            return 0
        n = len(grid)
        m = len(grid[0])
        uf = UF(n * m + 1)
        displacements = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        for i in xrange(n):
            for j in xrange(m):
                if grid[i][j] == '0':
                    uf.connect(i * m + j, n * m)
                else:
                    for di, dj in displacements:
                        if 0 <= i + di < n and 0 <= j + dj < m and grid[i + di][j + dj] == '1':
                            uf.connect(i * m + j, (i + di) * m + j + dj)

        return uf.getCount() - 1

sol = Solution()
grid = [['1', '1', '0', '0', '0'], ['1', '1', '0', '0', '0'], ['0', '0', '1', '0', '0'], ['0', '0', '0', '1', '1']]
print sol.numIslands(grid)




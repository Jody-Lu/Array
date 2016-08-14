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
    def solve(self, board):
        if not board:
            return []
        n = len(board)
        m = len(board[0])
        uf = UF(n * m + 1)

        for i in xrange(n):
            for j in xrange(m):
                if (i == 0 or i == n - 1 or j == 0 or j == m - 1) and board[i][j] == 'O':
                    uf.connect(i * m + j, n * m)
                # BFS
                elif board[i][j] == 'O':
                    if board[i - 1][j] == 'O':
                        uf.connect(i * m + j, (i - 1) * m + j)
                    if board[i + 1][j] == 'O':
                        uf.connect(i * m + j, (i + 1) * m + j)
                    if board[i][j - 1] == 'O':
                        uf.connect(i * m + j, i * m + j - 1)
                    if board[i][j + 1] == 'O':
                        uf.connect(i * m + j, i * m + j + 1)

        for i in xrange(n):
            for j in xrange(m):
                if not uf.connected(i * m + j, n * m):
                    board[i][j] = 'X'

sol = Solution()
board = [list("XXXX"), list("XOOX"), list("XOOX"), list("XXXX")]
print board
sol.solve(board)
print board



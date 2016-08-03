class Solution(object):
    def __init__(self):
        # go right, left, up, down
        self.dx = [1, -1, 0, 0]
        self.dy = [0, 0, 1, -1]
        self.row_lenght = 0
        self.col_length = 0
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        self.row_length = len(grid[0])
        self.col_length = len(grid)

        def removeIsland(x, y):
            grid[x][y] = '0'
            for i in xrange(4):
                nextX = x + self.dx[i]
                nextY = y + self.dy[i]
                if nextX >=0 and \
                   nextX < self.row_length and \
                   nextY >= 0 and \
                   nextY < self.col_length:
                       if grid[nextX][nextY] == '1':
                           removeIsland(nextX, nextY)
        res = 0
        for x in xrange(self.col_length):
            for y in xrange(self.row_length):
                if grid[x][y] == '1':
                    res += 1
                    removeIsland(x, y)
                else:
                    continue
        return res

sol = Solution()
grid = [['1', '1', '1', '1', '0'], ['1', '1', '0', '1', '0'], ['1', '1', '0', '0', '0'], ['0', '0', '0', '0', '0']]
print sol.numIslands(grid)

class Solution(object):
    def __init__(self):
        # go right, left, up, down
        self.dx = [1, -1, 0, 0]
        self.dy = [0, 0, 1, -1]
        self.y_lenght = 0
        self.x_length = 0
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        self.x_length = len(grid[0])
        self.y_length = len(grid)

        def removeIsland(y, x):
            grid[y][x] = '0'
            for i in xrange(4):
                nextX = x + self.dx[i]
                nextY = y + self.dy[i]

                if 0 <= nextX < self.x_length and \
                   0 <= nextY < self.y_length and \
                   grid[nextY][nextX] == '1':
                       removeIsland(nextY, nextX)
        res = 0
        for y in xrange(self.y_length):
            for x in xrange(self.x_length):
                if grid[y][x] == '1':
                    res += 1
                    removeIsland(y, x)
                else:
                    continue
        return res

sol = Solution()
grid = [['1', '1', '1', '1', '0'], ['1', '1', '0', '1', '0'], ['1', '1', '0', '0', '0'], ['0', '0', '0', '0', '0']]
print sol.numIslands(grid)

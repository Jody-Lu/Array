"""
Any non surrounded region must connect to a 'O' at the boundary.
Traverse all 'O' on the bounding and appply BFS on that.

"""
import collections
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        displacements = [[1, 0], [-1, 1], [-1, -1], [1, -1]]

        def bfs(i, j, m, n):
            dq = collections.deque([[i, j]])
            board[i][j] = 'B'
            while dq:
                i, j = dq.popleft()
                for di, dj in displacements:
                    i += di
                    j += dj
                    if 0 <= i < m and 0 <= j < n and board[i][j] == 'O':
                        dq.append([i, j])
                        board[i][j] = 'B'

        m, n = len(board), len(board[0])

        for i in xrange(m):
            for j in [0, n - 1]:
                if board[i][j] == 'O':
                    bfs(i, j, m, n)

        for i in [0, m - 1]:
            for j in xrange(n):
                if board[i][j] == 'O':
                    bfs(i, j, m, n)

        for i in xrange(m):
            for j in xrange(n):
                if board[i][j] != 'X':
                    board[i][j] = 'X' if board[i][j] == 'O' else 'O'

sol = Solution()
board = [list("XXXX"), list("XOOX"), list("XOOX"), list("XOXX")]
sol.solve(board)




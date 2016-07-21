class Solution(object):
    def maximalSquare(self, matrix):
        r_length = len(matrix[0])
        c_length = len(matrix)

        for i in xrange(c_length):
            for j in xrange(1, r_length):
                if matrix[i][j - 1] > 0 and matrix[i][j] > 0:
                    matrix[i][j] += matrix[i][j - 1]

        for i in xrange(r_length):
            for j in xrange(1, c_length):
                if matrix[j - 1][i] > 0 and matrix[j][i]:
                    matrix[j][i] += matrix[j - 1][i]
        print matrix

sol = Solution()
matrix = [[1, 0, 1, 0, 0],
          [1, 0, 1, 1, 1],
          [1, 1, 1, 1, 1],
          [1, 0, 0, 1, 0]]
print matrix
sol.maximalSquare(matrix)

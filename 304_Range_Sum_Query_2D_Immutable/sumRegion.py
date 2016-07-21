class NumMatrix(object):
    def __init__(self, matrix):
        """
        Initialize your data structure here.
        :type matrix: List[List[int]]
        """
        if not matrix:
            self.sumMatrix = []
        else:
            r_length = len(matrix[0]) + 1
            c_length = len(matrix)
            self.sumMatrix = [[0] * r_length for _ in xrange(c_length)]
            for i in xrange(c_length):
                for j in xrange(1, r_length):
                    self.sumMatrix[i][j] = self.sumMatrix[i][j - 1] + matrix[i][j - 1]

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1, col1)..(row2, col2)], inclusive
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        if not self.sumMatrix: return 0
        res = 0
        for i in xrange(row1, row2 + 1):
            res += self.sumMatrix[i][col2 + 1] - self.sumMatrix[i][col1]
        return res
"""
matrix = [[3, 0, 1, 4, 2],
          [5, 6, 3, 2, 1],
          [1, 2, 0, 1, 5],
          [4, 1, 0, 1, 7],
          [1, 0, 3, 0, 5]]
"""
matrix = []
numMatrix = NumMatrix(matrix)
print numMatrix.sumRegion(2, 1, 4, 3) 

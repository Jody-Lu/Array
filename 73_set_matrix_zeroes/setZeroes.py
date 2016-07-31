class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        Use row & col to record the row, col that have '0'
        """
        row_num = len(matrix)
        col_num = len(matrix[0])
        row = [False] * row_num
        col = [False] * col_num

        # 1st time survey the matrix 
        # To find which col/row has zero
        # We don't need and NxN matrix to memorize it
        # If a col/row has a zero, then the others are not necessary.
        for i in xrange(row_num):
            for j in xrange(col_num):
                if matrix[i][j] == 0:
                    row[i] = True
                    col[j] = True

        # 2nd time survey the matrix
        for i in xrange(row_num):
            for j in xrange(col_num):
                if row[i] or col[j]:
                    matrix[i][j] = 0




if __name__ == '__main__':
    matrix = [[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
    sol = Solution()
    sol.setZeroes(matrix)
    print matrix

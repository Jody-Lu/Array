##73 Set Matrix Zeroes

**Algorithm**

1. If we just survey the matrix and set it zero, we will set the whole matrix zero.
2. We use ``row`` and ``col`` to store which row or column has at least one zero in it. ``row[i] == True`` stands that there exists at least one zero in row i.
3. We survey the matrix again. With ``row`` and ``col``, we set ``matrix[i][j]`` zero if either ``row[i]`` or ``col[j]`` is zero.


**Code**

```python
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
``` 
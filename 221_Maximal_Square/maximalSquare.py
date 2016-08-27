class Solution(object):
    def maximalSquare(self, matrix):
        if not matrix: return 0
        m, n = len(matrix[0]), len(matrix)
        P = [[0] * m for _ in xrange(n)]
        maxArea = 0
        
        for i in xrange(m):
            P[0][i] = 0 if matrix[0][i] == '0' else 1
            maxArea = max(maxArea, P[0][i] ** 2)
        for j in xrange(n):
            P[j][0] = 0 if matrix[j][0] == '0' else 1
            maxArea = max(maxArea, P[j][0] ** 2)
        for i in xrange(1, n):
            for j in xrange(1, m):
                if matrix[i][j] == '0':
                    P[i][j] = 0
                else:
                    P[i][j] = 1 + min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) 
                maxArea = max(maxArea, P[i][j] ** 2)
        
        return maxArea


sol = Solution()
matrix = [['1', '0', '1', '0', '0'],
          ['1', '0', '1', '1', '1'],
          ['1', '1', '1', '1', '1'],
          ['1', '0', '0', '1', '0']]
#print matrix
print sol.maximalSquare(matrix)

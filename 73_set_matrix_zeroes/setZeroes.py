class Solution(object):
    def zero_row(self, matrix):
        pass
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        flag = False
        
        for row in matrix:
            if 0 in row:
                flag = True
                break
        
        if flag:
            for idx in range(len(matrix)):
                matrix[idx] = [0]*len(matrix[idx])
        

if __name__ == '__main__':
    matrix = [[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
    sol = Solution()
    sol.setZeroes(matrix)
    print matrix

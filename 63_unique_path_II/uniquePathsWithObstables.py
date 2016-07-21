class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        length = len(obstacleGrid[0])
        width = len(obstacleGrid)
        
        #print obstacleGrid
        obstacleGrid[0][0] = 0 if obstacleGrid[0][0] == 1 else 1
        
        for i in range(1, length):
            if obstacleGrid[0][i] == 1:
                obstacleGrid[0][i] = 0
            else:
                obstacleGrid[0][i] = obstacleGrid[0][i-1]

        for j in range(1, width):
            if obstacleGrid[j][0] == 1:
                obstacleGrid[j][0] = 0
            else:
                obstacleGrid[j][0] = obstacleGrid[j-1][0]
        
        #print obstacleGrid 
       
        for i in range(1, width):
            for j in range(1, length):
                if obstacleGrid[i][j] == 1:
                    obstacleGrid[i][j] = 0
                else:
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]

        #print obstacleGrid
        return obstacleGrid[width-1][length-1]


if __name__ == '__main__':
    sol = Solution()
    obstacleGrid = [[1, 0]]
    print sol.uniquePathsWithObstacles(obstacleGrid)





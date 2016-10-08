class Solution(object):
    def getMin(self, ac_point):
        minimum = ac_point.keys()[0]
        for k in ac_point.keys():
            if ac_point[k] < ac_point[minimum]:
                minimum = k

        return minimum
    
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not heightMap:
            return 0
        INF = 2 ** 31 - 1
        mm = len(heightMap)
        nn = len(heightMap[0])
        water = [[0] * nn for _ in xrange(mm)]
        ac_point = {}
        
        for i in xrange(mm):
            for j in xrange(nn):
                if i == 0 or i == mm - 1:
                    water[i][j] = heightMap[i][j]
                    ac_point[(i, j)] = heightMap[i][j]
                elif j == 0 or j == nn - 1:
                    water[i][j] = heightMap[i][j]
                    ac_point[(i, j)] = heightMap[i][j] 
                else:
                    water[i][j] = INF

        dd = {(0, 1), (0, -1), (-1, 0), (1, 0)}
        
        while ac_point:
            m = self.getMin(ac_point)
            ac_point.pop(m)
            y, x = m[0], m[1] # P
            for dx, dy in dd:
                if(0 <= x + dx < nn and 0 <= y + dy < mm):
                    tmp = water[y + dy][x + dx]
                    water[y + dy][x + dx] = max(heightMap[y + dy][x + dx], min(water[y + dy][x + dx], water[y][x]))
                    if water[y + dy][x + dx] != tmp:
                        ac_point[(y + dy, x + dx )] = water[y + dy][x + dx]

        print water
        res = 0
        for i in xrange(mm):
            for j in xrange(nn):
                res = max(res, water[i][j])

        return res





sol = Solution()
heightMap = [[1,3,3,1,3,2],[3,2,1,3,2,3],[3,3,3,2,3,1]]
print sol.trapRainWater(heightMap)

                

class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype int
        """
        T = []
        for i in range(len(triangle)):
            T.append([0]*(i+1))
            
        T[0][0] = triangle[0][0]
        
        for layer in range(1, len(triangle)):
            T[layer][0] = T[layer - 1][0] + triangle[layer][0]
            T[layer][-1]= T[layer - 1][-1] + triangle[layer][-1]
            for idx in range(1, len(triangle[layer]) - 1):
                T[layer][idx] = min(T[layer - 1][idx], T[layer - 1][idx - 1]) + triangle[layer][idx]
        print T 
        return min(T[-1])
    
if __name__ == '__main__':
    sol = Solution()
    triangle = [[2], [3,4], [6,5,7], [4,1,8,3]]
    print sol.minimumTotal(triangle)


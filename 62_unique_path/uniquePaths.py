import math

class Solution(object):
    def uniquePaths_dynamic(self, m, n):
        T =[[1]*n]*m
        for i in range(1, len(T)):
            for j in range(1, len(T[0])):
                T[i][j] = T[i-1][j] + T[i][j-1]
        return T[m-1][n-1]
    
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        m = m - 1
        n = n - 1 
        tmp = 1
        for i in range(1, n + 1):
            tmp *= m + i
        return tmp / math.factorial(n)

if __name__ == '__main__':
    sol = Solution()
    m = 3
    n = 7
    print sol.uniquePaths_dynamic(m, n)

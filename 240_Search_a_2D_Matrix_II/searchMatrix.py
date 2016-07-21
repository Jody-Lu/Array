class Solution(object):
    def searchMatrix(self, matrix, target):
        m = len(matrix)
        n = len(matrix[0])
        
        for i in range(m):
            if target > matrix[i][-1]:
                continue
            if target < matrix[i][0]:
                break
            begin = 0
            end = n
            while begin <= end:
                mid = (begin + end) / 2
                if matrix[i][mid] == target: 
                    return True
                if target > matrix[i][mid]:
                    begin = mid + 1
                else:
                    end = mid - 1
            else:
                continue
        
        return False
            

sol = Solution()
matrix = [ [1,   4,  7, 11, 15],
           [2,   5,  8, 12, 19],
           [3,   6,  9, 16, 22],
           [10, 13, 14, 17, 24],
           [18, 21, 23, 26, 30]]

target = 18
print sol.searchMatrix(matrix, target)


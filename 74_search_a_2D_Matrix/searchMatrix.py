class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        start = 0
        end = len(matrix) - 1

        while start <= end:
            pin = (start + end) / 2
            if matrix[pin][0] == target:
                return True
            if matrix[pin][0] < target:
                start = pin + 1
            else:
                end = pin - 1

        Result = True

        if pin == 0:
            return target in matrix[pin]

        if pin == len(matrix) - 1:
            return target in matrix[pin] or target in matrix[pin - 1]

        Result = target in matrix[pin] or target in matrix[pin - 1] or target in matrix[pin + 1]

        return Result

if __name__ == '__main__':
    sol = Solution()
    matrix = [ [1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 50]]
    target = 6
    print sol.searchMatrix(matrix, target)

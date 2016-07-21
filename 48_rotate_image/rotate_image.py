import copy

class Solution(object):
	def rotate(self, matrix):
		"""
		:type matrix: List[List[int]]
		:rtype: void Do not return anything, modify matrix in-place instead.
		"""
		temp = copy.deepcopy(matrix) # create a temp matrix to save matrix
		dimension = len(matrix) # dimension of the matrix
		for row in range(0, dimension):
			for column in range(0, dimension):
				matrix[column][dimension - row - 1] = temp[row][column]


if __name__ == '__main__':
	sol = Solution()
	matrix = [[1, 2, 3], [4, 5, 6], [7,8,9] ]
	print matrix
	sol.rotate(matrix)
	print matrix
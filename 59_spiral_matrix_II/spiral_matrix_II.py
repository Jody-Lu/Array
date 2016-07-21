class Solution(object):
    def generateMatrix(self, n):
        """
        : type n: int
        : rtype: List[List[int]]
        """
        array = [i + 1 for i in range(0, n**2)]

        result = [[0 for i in range(0, n)] for j in range(0, n)]

        beginX = 0
        endX = n - 1

        beginY = 0
        endY = n - 1

        count = 0


        while True:
            # From left to right
            for i in range(beginX, endX + 1):
            	result[beginY][i] = array[count]
            	count += 1
            beginY += 1
            if beginY > endY:
            	break
            # From top to bottom
            for j in range(beginY, endY + 1):
            	result[j][endX] = array[count]
            	count += 1
            endX -= 1
            if endX < beginX:
            	break
            # From right to left
            for i in reversed(range(beginX, endX + 1)):
            	result[endY][i] = array[count]
            	count += 1
            endY -= 1
            if endY < beginY:
            	break
            # From bottom to top
            for j in reversed(range(beginY, endY + 1)):
            	result[j][beginX] = array[count]
            	count += 1
            beginX += 1 
            if beginX > endX:
            	break

        return result


if __name__ == '__main__':
	sol = Solution()
	n = 6;
	result = sol.generateMatrix(n)
	print result


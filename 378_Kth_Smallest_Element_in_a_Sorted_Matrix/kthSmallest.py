from heapq import heappush, heappop, heapreplace, heapify
class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        index = 1
        h = [(row[0], row, index) for row in matrix]
        heapify(h)

        for _ in xrange(k - 1):
            v, r, i = h[0]
            if i < len(r):
                heapreplace(h, (r[i], r, i + 1))
            else:
                heappop(h)

        return h[0][0]

sol = Solution()
matrix = [[ 1,  5,  9], [10, 11, 13], [12, 13, 15]]
k = 8
print sol.kthSmallest(matrix, k)

            
        

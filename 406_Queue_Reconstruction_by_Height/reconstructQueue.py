class Solution(object):
    def reconstructQueue(self, p):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(p)
        res = []
        maxH = 0
        
        for i in xrange(n):
            maxH = max(maxH, p[i][0])
        
        for i in xrange(n):
            if p[i][0] == maxH:
                res.append(p[i])

        for i in xrange(n):
            if p[i][0] != maxH:
                res.insert(p[i][1], p[i]) 
                #print res
        return res

sol = Solution()
p = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
print sol.reconstructQueue(p)

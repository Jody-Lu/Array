class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort()
        for idx in xrange(len(citations)):
            for j in xrange(citations[idx] + 1):
                if j == len(citations) - idx:
                    return j
        return 0


sol = Solution()
citations = []
print sol.hIndex(citations)

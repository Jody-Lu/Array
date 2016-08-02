class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort()
        length = len(citations)
        for idx in xrange(length):
            # We only have to check wheather citations[idx] >= (length - idx) 
            if citations[idx] >= (length - idx):
                return length - idx
        return 0


sol = Solution()
citations = []
print sol.hIndex(citations)

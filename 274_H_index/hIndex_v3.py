class Solution(object):
    def hIndex(self, citations):
        n = len(citations)
        citeCount = [0] * (n + 1)
        # citeCount[i]: number of works which have i citations
        # citeCount[n]: number of works which have n or more citations
        # i: number of citations
        for c in citations:
            if c >= n:
                citeCount[n] += 1
            else:
                citeCount[c] += 1
        print citeCount
        i = n - 1
        while i >= 0:
            citeCount[i] += citeCount[i + 1]
            if citeCount[i + 1] >= i + 1:
                return i + 1
            i -= 1
        return 0
        

sol = Solution()
citations = [3, 0, 6, 1, 5]
print sol.hIndex(citations)


class Solution(object):
    def hIndex(self, citations):
        """
        :type citation: List[int]
        :rtype int
        """
        if len(citations) == 0:
            return 0
        citations = list(set(citations))
        citations = sorted(citations)
        citations.reverse()
        citations.append(-1)
        dic_citation = {}
        numList = []

        for idx in range(len(citations)):

            dic_citation[idx + 1] = []

        for idx in range(len(citations) - 1):
            tmp = idx
            val = citations[tmp]
            while val >= citations[tmp + 1]:
                dic_citation[idx + 1].append(val)
                val -= 1

        for item in dic_citation.items():
            if item[0] in item[1]:
                numList.append(item[0])

        print dic_citation

        return max(numList) if len(numList) != 0 else 0


if __name__ == '__main__':
    citations = [1, 2, 2]
    sol = Solution()
    print sol.hIndex(citations)
            




class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        # Construct the graph
        res = ["JFK"]
        graph = {tick[0]:set() for tick in tickets}

        for f, t in tickets:
            graph[f].add(t)

        queue = ["JFK"]
        while queue:
            top = queue.pop()
            if top in graph and graph[top]:
                dest = min(graph[top])
                graph[top].remove(dest)
                res.append(dest)
                queue.append(dest)
            else:
                break

        return res



sol = Solution()
tickets = [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
#tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
#tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
print sol.findItinerary(tickets)



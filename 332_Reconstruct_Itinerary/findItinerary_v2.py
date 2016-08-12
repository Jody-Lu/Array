import collections
class Solution(object):
    def findItinerary(self, tickets):
        """
        DFS & Backtracking
        Find Euler Path --> Heirholzer's Algorithm
        """
        targets = collections.defaultdict(list)
        for f, t in sorted(tickets)[::-1]:
            targets[f] += t,
        route = []
        print targets
        def visit(airport):
            # Divide
            while targets[airport]:
                visit(targets[airport].pop())
            # Combine the path
            route.append(airport)
        visit("JFK")
        return route[::-1]


sol = Solution()
#tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
#tickets = [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
print sol.findItinerary(tickets)

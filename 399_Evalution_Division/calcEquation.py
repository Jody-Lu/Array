from math import isinf

class Solution(object):
    graph = []
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        INF = float('inf')
        nodes = set()
        m = {}

        for equ in equations:
            nodes |= {equ[0], equ[1]}

        count = 0
        for n in sorted(list(nodes)):
            m[n] = count
            count += 1

        V = len(nodes)
        self.graph = [[INF] * V for _ in xrange(V)]

        for idx, equ in enumerate(equations):
            self.graph[m[equ[0]]][m[equ[1]]] = values[idx]
            self.graph[m[equ[1]]][m[equ[0]]] = 1.0 / values[idx]

        for idx in xrange(V):
            self.graph[idx][idx] = 1.0


        for k in xrange(V):
            for i in xrange(V):
                for j in xrange(V):
                        self.graph[i][j] = min(self.graph[i][j], self.graph[i][k] * self.graph[k][j])


        res = []

        for q in queries:
            if q[0] not in nodes or q[1] not in nodes:
                res.append(-1.0)
            else:
                if not isinf(self.graph[m[q[0]]][m[q[1]]]):
                    res.append(self.graph[m[q[0]]][m[q[1]]])
                else:
                    res.append(-1.0)

        return res



sol = Solution()
equations = [["a","b"],["c","d"],["e","f"],["g","h"]]
values = [4.5,2.3,8.9,0.44]
queries = [["a","c"],["d","f"],["h","e"],["b","e"],["d","h"],["g","f"],["c","g"]]
print sol.calcEquation(equations, values, queries)


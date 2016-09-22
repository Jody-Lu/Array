from math import isinf

class Solution(object):
    def calcEquation(self, equations, values, queries):
        INF = float("inf")
        nodes = set()
        graph = {}

        for equ in equations:
            nodes |= {equ[0], equ[1]}

        for i in nodes:
            for j in nodes:
                if i == j: graph[(i, j)] = 1.0
                else: graph[(i, j)] = INF

        for (i, j), v in zip(equations, values):
            graph[(i, j)] = v
            graph[(j, i)] = 1.0 / v

        for k in nodes:
            for i in nodes:
                for j in nodes:
                    graph[(i, j)] = min(graph[(i, j)], graph[(i, k)] * graph[(k, j)])

        res = []
        for q in queries:
            if q[0] not in nodes or q[1] not in nodes:
                res.append(-1.0)
            else:
                if isinf(graph[(q[0], q[1])]):
                    res.append(-1.0)
                else: 
                    res.append(graph[(q[0], q[1])])
        return res

sol = Solution()
e = [ ["a", "b"], ["b", "c"] ]
v = [2.0, 3.0]
q = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]
print sol.calcEquation(e, v, q)

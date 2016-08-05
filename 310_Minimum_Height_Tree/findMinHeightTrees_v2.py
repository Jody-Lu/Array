"""
For a tree we can do some thing similar. We start from every end, by end we mean vertex of degree 1 (aka leaves). We let the pointers move the same speed. When two pointers meet, we keep only one of them, until the last two pointers meet or one step away we then find the roots.

It is easy to see that the last two pointers are from the two ends of the longest path in the graph.

The actual implementation is similar to the BFS topological sort. Remove the leaves, update the degrees of inner vertexes. Then remove the new leaves. Doing so level by level until there are 2 or 1 nodes left. What's left is our answer!

The time complexity and space complexity are both O(n).

Note that for a tree we always have V = n, E = n-1
"""
class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        Topological Sort
        """
        graph = {i:set() for i in xrange(n)}
        for x, y in edges:
            graph[x] |= {y}
            graph[y] |= {x}

        leaves = [i for i in xrange(n) if len(graph[i]) == 1]

        while n > 2:
            n -= len(leaves)
            newLeaves = []
            for i in leaves:
                j = graph[i].pop()
                graph[j].remove(i)
                if len(graph[j]) == 1:
                    newLeaves.append(j)
            #print newLeaves
            leaves = newLeaves
        return leaves

sol = Solution()
n = 8
edges = [[0, 2], [1, 2], [2, 3], [4, 3], [5, 4], [5, 6], [5, 7]]
print sol.findMinHeightTrees(n, edges)

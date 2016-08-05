class Solution(object):
    graph = {}
    leaves = []
    def height(self, root):
        """
        if root in self.leaves:
            return 1
        for n in self.graph[root]:
            self.height(n)
        """
        return 1 + min([self.height(n) for n in self.graph[root]]) if root not in self.leaves else 1
    
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        # Construct graph
        self.graph = {i:set() for i in xrange(n)}
        for x, y in edges:
            self.graph[x] |= {y}
            self.graph[y] |= {x}
        # got the leaves
        for node in self.graph:
            if len(self.graph[node]) == 1:
                self.leaves.append(node)

        print self.leaves
        print self.height(3)
        
        

sol = Solution()
n = 6
edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
sol.findMinHeightTrees(n, edges)

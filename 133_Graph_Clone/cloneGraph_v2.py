class Solution(object):
    def __init__(self):
        self.visited = {}
    def cloneGraph(self, node):
        if not node: 
            return None
        if node.label in self.visited:
            return self.visited[node.label]

        clone = UndirectedGraphNode(node.label)
        self.visited[node.label] = clone

        for neigh in node.label:
            clone.neighbors.append(self.cloneGraph(neigh))

        return clone




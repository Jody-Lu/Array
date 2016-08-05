class UndirectedGraphNode(object):
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: UndirectedGraphNode
        :rtype: UndirectedGraphNode
        """
        if not node:
            return None

        root = UndirectedGraphNode(node.label)
        # node.label: clone UndirectedGraphNode
        stack = [node]
        visit = {}
        visit[node.label] = root

        while stack:
            top = stack.pop()
            for n in top.neighbors:
                if n.label not in visit:
                    stack.append(n)
                    visit[n.label] = UndirectedGraphNode(n.label)
                visit[top.label].neighbors.append(visit[n.label])

        return root

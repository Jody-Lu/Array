#207. Course Schedule

**Algorithm**

1. This problem can transform into a graph problem.
2. If one cannot complete these courses, there must exist circle in this graph.
3. We use DFS to traverse the graph. If we meet a node is being visited, the circle existed.

**Code**

```python
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype bool
        """
        graph = [[] for _ in xrange(numCourses)]
        # 0: not visit, 1: been visited, -1: being visited
        visit = [0 for _ in xrange(numCourses)] 
        for x, y in prerequisites:
            graph[x].append(y)
        
        def dfs(i):
            print visit, i
            if visit[i] == -1:
                return False
            if visit[i] == 1:
                return True
            visit[i] = -1
            for j in graph[i]:
                if not dfs(j):
                    return False
            visit[i] = 1
            return True
        
        for i in xrange(numCourses):
            if not dfs(i):
                return False
        return True
```
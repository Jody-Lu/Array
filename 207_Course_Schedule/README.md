#207. Course Schedule

##DFS

**Algorithm - DFS**

1. This problem can transform into a graph problem.
2. If one cannot complete these courses, there must exist circle in this graph.
3. We use DFS to traverse the graph. If we meet a node is being visited, the circle existed.

**Code (DFS)**

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

##Topological Sort

**What is Topological Sort?**

**Ref:** http://www.csie.ntnu.edu.tw/~u91029/DirectedAcyclicGraph.html#2

1. Traverse from the nodes that have zero in-degree.
2. Each time we traverse a node, we remove its edge by removing the in-degree of the node it points to.
3. If the graph is DAG, we can complete the topological sort.  

**Why Topological Sort?**

Course Schedule can be represented with ``DAG (Directed Acylic Graph)`` (vertex: courses, edge: prerequisites) since if we direct the course to its prerequisites, there must not exist a cicle (i.e., if there exist a circle in the course shcedule, we will not be possible to complete the whole courses since the two course may be the prerequisite for each other and we cannot take each course first (somehow like ``Death Lock``)). So our task is to apply topological sort on the graph. If there exist a circle in the graph, we would not be able to complete the sort (i.e., the # visited node must less than ``numCourses``) 
 

**Algorithm - Topological Sort**

Taverse the prerequisite graph with topological sort. If there exist a circle in the graph, we cannot complete the traversal.

**Code (Topological Sort)**

```python 
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        Topological Sort
        """
        graph = {i:set() for i in xrange(numCourses)}
        indeg = {i:0 for i in xrange(numCourses)}
        # Construct the graph
        for s, e in set(tuple(x) for x in prerequisites):
            graph[s] |= {e}
            indeg[e] += 1
        # Get the zero in-degree node
        queue = [i for i in xrange(numCourses) if not indeg[i]]
        visits = set(queue)
        for node in queue:
            for neigh in graph[node]:
                if neigh in visits:
                    return False
                indeg[neigh] -= 1
                if not indeg[neigh]:
                    visits.add(neigh)
                    queue += neigh,

        return len(visits) == numCourses
```
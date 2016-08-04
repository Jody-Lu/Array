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


sol = Solution()
numCourses = 4
prerequisites = [[1, 0], [1, 2], [1, 3], [3, 2], [2, 3]]
print sol.canFinish(numCourses, prerequisites)


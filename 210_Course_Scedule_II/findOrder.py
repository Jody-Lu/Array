class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        res = []
        graph = {i:set() for i in xrange(numCourses)}
        indeg = {i:0     for i in xrange(numCourses)}

        for s, e in set(tuple(x) for x in prerequisites):
            graph[e] |= {s}
            indeg[s] += 1


        queue = [i for i in xrange(numCourses) if not indeg[i]]
        for node in queue:
            res.append(node)
            for neigh in graph[node]:
                indeg[neigh] -= 1
                if not indeg[neigh]:
                    queue += neigh,

        return res if len(res) == numCourses else []

sol = Solution()
numCourses = 4
prerequisites = [[1,0],[2,0],[3,1],[3,2]]
print sol.findOrder(numCourses, prerequisites)

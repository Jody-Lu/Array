#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

class Solution {
    public:
        bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
            vector<unordered_set<int> > graph = makeGraph(numCourses, prerequisites);
            vector<int> indegrees = computeIndegree(graph);
            for(int i = 0; i < numCourses; i++) {
                int j = 0;
                for(; j < numCourses; j++) {
                    if(!indegrees[j]) { break; }
                }
                if(j == numCourses) { return false; }
                indegrees[j] = -1;
                for(int neigh : graph[j]) {
                    indegrees[neigh] -= 1;
                }
            }

            return true;
        }

    private:
        vector<unordered_set<int> > makeGraph(int numCourses, vector<pair<int, int> >& prerequisites) {
            vector<unordered_set<int> > graph(numCourses);

            for(auto pre : prerequisites) {
                // [pre] = {courses}
                graph[pre.second].insert(pre.first);
            }
            return graph;
        }

        vector<int> computeIndegree(vector<unordered_set<int> >& graph) {
            vector<int> degrees(graph.size(), 0);

            for(auto neighbors : graph) {
                for(int neigh : neighbors) {
                    degrees[neigh]++;
                }
            }

            return degrees;
        }

};

#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
            vector<unordered_set<int> > graph = makeGraph(numCourses, prerequisites);
            vector<int> degree = countInDegree(graph);
            vector<int> res;

            for(int i = 0; i < numCourses; i++) {
                int j = 0;
                for(; j < numCourses; j++) {
                    if(degree[j] == 0) { break; }
                }
                if(j == numCourses) { return vector<int>(); } 
                res.push_back(j);
                degree[j] = -1;
                for(int neigh : graph[j]) {
                    degree[neigh]--;
                }
            }

            return res;

        }

    private:
        vector<unordered_set<int> > makeGraph(int numCourses, vector<pair<int, int> >& prerequisites) {
            vector<unordered_set<int> > graph(numCourses);

            for(auto pre : prerequisites) {
                graph[pre.second].insert(pre.first);
            }

            return graph;
        }

        vector<int> countInDegree(vector<unordered_set<int> >& graph) {
            vector<int> degree(graph.size(), 0);

            for(auto neighbors : graph) {
                for(int neigh : neighbors) {
                    degree[neigh]++;
                }
            }

            return degree;
        }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

        // corner case - no edge
        if(edges.size() == 0) { return vector<int>(1, 0); }

        vector<unordered_set<int> > graph = makeGraph(n, edges);
        vector<int> leaves, newLeaves;
        int count = n;

        for(int i = 0; i < n; i++) {
            if(graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        while(count > 2) {
            count -= leaves.size();

            for(int i : leaves) {
                int j = *(graph[i].begin());
                graph[i].erase(j);
                graph[j].erase(i);
                if(graph[j].size() == 1) {
                    newLeaves.push_back(j);
                }
            }

            swap(leaves, newLeaves);
            newLeaves.clear();
        }

        return leaves;
    }

private:
    vector<unordered_set<int> > makeGraph(int n, vector<pair<int, int> >& edges) {
        vector<unordered_set<int> > graph(n);

        for(auto e : edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }

        return graph;
    }
};
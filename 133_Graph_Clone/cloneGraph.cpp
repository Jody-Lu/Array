#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x): label(x) {}
};

class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if(!node) return NULL;

            auto it = visited.find(node->label);
            if(it != visited.end())
                return visited[node->label];

            UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
            visited[node->label] = clone;

            for(int i = 0; i < node->neighbors.size(); i++)
                clone->neighbors.push_back(cloneGraph((node->neighbors)[i]));

            return clone;
        }
    private:
        unordered_map<int, UndirectedGraphNode*> visited;
};

int main() {
    return 0;
}

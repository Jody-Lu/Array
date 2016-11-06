class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> nodes(n, 0);
        for(int i = 0; i < n; i++) { nodes[i] = i; }
        for(auto e : edges) {
            int f = e.first;
            int s = e.second;
            while(nodes[f] != f) { f = nodes[f]; }
            while(nodes[s] != s) { s = nodes[s]; }
            // check cycle
            if(f == s) { return false; }
            nodes[s] = f;
        }

        return (edges.size() == n - 1);
    }
};
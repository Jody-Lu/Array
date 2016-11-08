class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        id.resize(n);

        for(int i = 0; i < n; i++) {
            id[i] = i;
        }

        for(auto e : edges) {
            int f = e.first;
            int s = e.second;
            if(find(f) == find(s)) {
                return false;
            }
            else {
                unions(f, s);
            }
        }

        return (edges.size() == n - 1);
    }
private:
    vector<int> id;

    void unions(int p, int q) {
        int x = find(p);
        int y = find(q);
        if(x != y) {
            id[x] = y;
        }
    }

    int find(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }

        return i;
    }

};

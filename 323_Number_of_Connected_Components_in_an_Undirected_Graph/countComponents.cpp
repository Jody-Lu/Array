class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int res = n;
        id.resize(n);

        for(int i = 0; i < n; i++) {
            id[i] = i;
        }

        for(auto e : edges) {
            int f = e.first;
            int s = e.second;
            if(find(f) != find(s)) {
                res--;
                unions(f, s);
            }

        }

        return res;
    }

private:
    vector<int> id;

    int find(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }

        return i;
    }

    void unions(int p, int q) {
        int x = find(p);
        int y = find(q);
        if(x != y) {
            id[x] = y;
        }
    }
};
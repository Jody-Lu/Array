class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int m = grid.size();

        if(m == 0) { return 0; }

        int n = grid[0].size();
        count = 0;

        vector<int> roots(m * n + 1, 0);
        //roots[n * m] = n * m;

        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int root = i * n + j;
                roots[root] = root;

                if(grid[i][j] == '0') {
                    unions(roots, n * m, root);
                }
                else {
                    count++;
                    for(int k = 0; k < 4; k++) {
                        int nextI = i + di[k];
                        int nextJ = j + dj[k];
                        int nb = nextI * n + nextJ;
                        if(nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n || grid[nextI][nextJ] == '0') {
                            continue;
                        }

                        if(find(roots, nb) != find(roots, root)) {
                            unions(roots, root, nb);
                            count--;
                        }

                    }
                }
            }
        }

        return count;
    }

private:
    int count;
    void unions(vector<int>& roots, int p, int q) {
        int x = find(roots, p);
        int y = find(roots, q);
        if(x != y) {
            roots[y] = x;
        }
        count--;
    }

    int find(vector<int>& roots, int i) {
        while(i != roots[i]) {
            roots[i] = roots[roots[i]];
            i = roots[i];
        }
        return i;
    }

};
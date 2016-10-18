#include <vector>

using namespace std;

class UF {
public:
    UF(int N): count(N) {
        for(int i = 0; i < N; i++) {
            id.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int p) {
        while(p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int getCount() {
        return count;
    }

    void connect(int p, int q) {
        int i = find(p);
        int j = find(q);

        if(i == j)
            return;
        if(rank[i] < rank[j])
            id[i] = j;
        else if(rank[i] > rank[j])
            id[j] = i;
        else {
            id[j] = i;
            rank[i] += 1;
        }
        count--;
    }

private:
    vector<int> id;
    vector<int> rank;
    int count;
};

class Solution {
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        UF uf(m * n + 1);
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int y = 0; y < m; y++) {
            for(int x = 0; x < n; x++) {
                if(grid[y][x] == '0')
                    uf.connect(y * m + x, n * m);
                else {
                    for(int i = 0; i < 4; i++) {
                        int nextX = x + dx[i];
                        int nextY = y + dy[i];
                        if(nextX >= 0 && nextX < n && 
                           nextY >= 0 && nextY < m &&
                           grid[nextY][nextX] == '1')
                            uf.connect(y * m + x, nextX * m + nextY);
                    }
                }
            }
        }
        return uf.getCount() - 1;
    }
};

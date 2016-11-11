#include <iostream>
#include <vector>
#include <utility>

using namespace std;


class Solution {
    public:
        vector<int> numIslands2(int m, int n, vector<pair<int, int> >& positions) {
            vector<int> res;
            // corner case:
            if(m <= 0 || n <= 0) { return res; }
            int count = 0;
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};

            vector<int> roots(m * n, -1);

            for(auto pos : positions) {
                int root = n * pos.first + pos.second;
                roots[root] = root;
                count++; // add one island

                for(int i = 0; i < 4; i++) {
                    int nextX = pos.first + dx[i];
                    int nextY = pos.second + dy[i];
                    int nb = n * nextX + nextY;

                    if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || roots[nb] == -1) {
                        continue;
                    }

                    int rootNb = find(roots, nb);
                    // unions the adjacents
                    if(rootNb != root) {
                        unions(roots, root, nb);
                        count--;
                    }
                }
                res.push_back(count);
            }

            return res;
        }
    private:
        void unions(vector<int>& roots, int p, int q) {
            int x = find(roots, p);
            int y = find(roots, q);
            if(x != y) {
                roots[y] = x;
            }
        }

        int find(vector<int>& roots, int id) {
            while(id != roots[id]) {
                roots[id] = roots[roots[id]];
                id = roots[id];
            }

            return id;
        }
};

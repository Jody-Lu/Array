#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = m? grid[0].size() : 0;

        vector<vector<int> > reach(m, vector<int>(n, 0));
        vector<vector<int> > distance(m, vector<int>(n, 0));
        pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int building = 0, res = INT_MAX;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    building++;
                    int dist = 0;
                    vector<vector<bool> > visited(m, vector<bool>(n, false));
                    queue<pair<int,int> > curr, next;
                    curr.emplace(i, j);

                    while(!curr.empty()) {
                        ++dist;
                        while(!curr.empty()) {
                            pair<int, int> cur = curr.front();
                            curr.pop();
                            reach[cur.first][cur.second]++;

                            for(int i = 0; i < 4; i++) {
                                int nextY = cur.first + dir[i].first;
                                int nextX = cur.second + dir[i].second;
                                if(nextY >= 0 && nextY < m && nextX >= 0 && nextX < n && grid[nextY][nextX] == 0 && !visited[nextY][nextX])
                                {
                                    distance[nextY][nextX] += dist;
                                    next.emplace(nextY, nextX);
                                    visited[nextY][nextX] = true;
                                }
                            }

                        }
                        swap(curr, next);
                    }
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0 && reach[i][j] == building) {
                    res = min(res, distance[i][j]);
                }
            }
        }

        return (res == INT_MAX)? -1 : res;

    }
};

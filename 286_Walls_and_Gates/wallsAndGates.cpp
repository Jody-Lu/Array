#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

class Solution {
    public:
        void wallsAndGates(vector<vector<int> >& rooms) {
            int m = rooms.size();
            if(m == 0) { return; }
            int n = rooms[0].size();

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(rooms[i][j] == 0) {
                        bfs(rooms, i, j);
                    }
                }
            }
        }

    private:
        void bfs(vector<vector<int> >& rooms, int y, int x) {
            int m = rooms.size(), n = rooms[0].size();
            queue<pair<int, int> > q;
            pair<int, int> diff[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            q.emplace(make_pair(y, x));

            while(!q.empty()) {
                pair<int, int> curr = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int adjY = curr.first + diff[i].first;
                    int adjX = curr.second + diff[i].second;

                    if(adjY >= 0 && adjY < m &&
                       adjX >= 0 && adjX < n &&
                       rooms[adjY][adjX] > rooms[curr.first][curr.second]) {
                        rooms[adjY][adjX] = rooms[curr.first][curr.second] + 1;
                        q.emplace(make_pair(adjY, adjX));
                    }
                }
            }
        }
};

#include <vector>

using namespace std;

class Solution {
	public:
        void removeIsland(vector<vector<char> >& grid, int y, int x) {
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};
            int m = grid.size(), n = grid[0].size();

            grid[x][y] = '0';
            for(int i = 0; i < 4; i++) {
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                if(nextX >= 0 && nextX < n &&
                   nextY >= 0 && nextY < m &&
                   grid[nextX][nextY] == '1') {
                    removeIsland(grid, nextX, nextY);
                }
            }
        }
    	int numIslands(vector<vector<char> >& grid) {
            int res = 0;
            for(int y = 0; y < grid.size(); y++) {
                for(int x = 0; x < grid[0].size(); x++) {
                    if(grid[y][x] == '1') {
                        res++;
                        removeIsland(grid, y, x);
                    }
                }
            }
            return res;
    	}
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        int m = matrix.size();
        if(m == 0) { return 0; }
        int n = matrix[0].size();
        int res = 1;

        vector<vector<int> > cache(m, vector<int>(n, 0)); // memorization

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res = max(res, bfs(matrix, i, j, cache));
            }
        }

        return res;
    }

private:
    int bfs(vector<vector<int> >& matrix, int y, int x, vector<vector<int> >& cache) {
        if(cache[y][x] != 0) {
            return cache[y][x];
        }

        int MaxLen = 1;
        int m = matrix.size(), n = matrix[0].size();
        pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int i = 0; i < 4; i++) {
            int nextY = y + dir[i].first;
            int nextX = x + dir[i].second;

            if(nextY < 0 || nextY >= m || nextX < 0 || nextX >= n || matrix[nextY][nextX] <= matrix[y][x])
            {
                continue;
            }
            int len = 1 + bfs(matrix, nextY, nextX, cache);
            MaxLen = max(MaxLen, len);
        }

        cache[y][x] = MaxLen;
        return MaxLen;
    }
};
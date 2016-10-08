#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
    	int trapRainWater(vector<vector<int> >& heightMap) {
            int m = heightMap.size();
            int n = heightMap[0].size();
            int res = 0;
            vector<vector<int> > left(m , vector<int>(n, 0));
            vector<vector<int> > right(m, vector<int>(n, 0));
            vector<vector<int> > up(m, vector<int>(n, 0));
            vector<vector<int> > down(m, vector<int>(n, 0));

            for(int i = 0; i < m; i++)
            {
                left[i][0] = heightMap[i][0];
                for(int j = 1; j < n; j++)
                {
                    left[i][j] = max(left[i][j - 1], heightMap[i][j]);
                }
            }

            for(int i = 0; i < m; i++)
            {
                right[i][n - 1] = heightMap[i][n - 1];
                for(int j = n - 2; j >= 0; j--)
                {
                    right[i][j] = max(right[i][j + 1], heightMap[i][j]);
                }
            }

            for(int j = 0; j < n; j++)
            {
                up[0][j] = heightMap[0][j];
                for(int i = 1; i < m; i++)
                {
                    up[i][j] = max(up[i - 1][j], heightMap[i][j]);
                }
            }

            for(int j = 0; j < n; j++)
            {
                down[m - 1][j] = heightMap[m - 1][j];
                for(int i = m - 2; i >= 0; i--)
                {
                    down[i][j] = max(down[i + 1][j], heightMap[i][j]);
                }
            }

            for(int i = 1; i < m - 1; i++)
            {
                for(int j = 1; j < n - 1; j++)
                {
                    res += (min(min(left[i][j], right[i][j]),
                               min(up[i][j], down[i][j])) - heightMap[i][j]);
                }
            }
            return res;
    	}
};
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maximalSquare(vector<vector<char> >& matrix) {
            if(matrix.size() == 0) return 0;
            vector<vector<int> > P(matrix.size(), vector<int>(matrix[0].size(), 0));
            int m = matrix[0].size(), n = matrix.size();
            int maxArea = INT_MIN;
            for(int i = 0; i < m; i++)
                P[0][i] = matrix[0][i] == '0'? 0 : 1;
            for(int i = 0; i < n; i++)
                P[i][0] = matrix[i][0] == '0'? 0 : 1;

            for(int i = 1; i < n; i++) {
                for(int j = 1; j < m; j++) {
                    if(matrix[i][j] == '0') P[i][j] = 0;
                    else {
                        P[i][j] = 1 + min(min(P[i - 1][j], P[i][j - 1]), P[i - 1][j - 1]);
                    }
                }
            }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    maxArea = max(maxArea, P[i][j] * P[i][j]);
            return maxArea;
        }
};

int main() {
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maximalRectangle(vector<vector<char> >& matrix) {
            if(matrix.size() == 0) return 0;
            int m = matrix.size(), n = matrix[0].size();
            vector<vector<int> > T(m + 1, vector<int>(n + 1, 0));
            int maxArea = INT_MIN;

            for(int i = 1; i <= m; i++)
                if(matrix[i - 1][0] == '0') T[i][0] = 0;
                else if(matrix[i - 1][0] == '1') {
                    T[i][0] = 1 + T[i - 1][0];
                    maxArea = max(maxArea, T[i][0]);
                }

            for(int j = 0; j <= n; j++)
                if(matrix[0][j - 1] == '0') T[0][j] = 0;
                else if(matrix[0][j - 1] == '1') {
                    T[0][j] = 1 + T[0][j - 1];
                    maxArea = max(maxArea, T[0][j]);
                }

            for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= n; j++) {
                    if(matrix[i - 1][j - 1] == '0') 
                        T[i][j] = 0;
                    else
                        T[i][j] = max(T[i - 1][j], max(T[i][j - 1], T[i - 1][j - 1]));
                }
            }

            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= n; j++)
                    cout << T[i][j] << " ";
                cout << endl;
            }

            return 0;
        }
};

int main() {
    return 0;
}

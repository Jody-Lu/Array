#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maximalRectangle(vector<vector<char> >& matrix) {
            if(matrix.size() == 0) return 0;
            int n = matrix[0].size(), m = matrix.size();
            vector<int> height(n, 0);
            vector<int> left(n, 0);
            vector<int> right(n, n);
            int maxArea = 0;

            for(int i = 0; i < m; i++) {
                int curr_left = 0, curr_right = n;
                
                for(int j = 0; j < n; j++)
                    if(matrix[i][j] == '1') height[j]++;
                    else height[j] = 0;

                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] == '1')
                        left[j] = max(curr_left, left[j]);
                    else {
                        curr_left = j + 1;
                        left[j] = 0;
                    }
                }
                /*
                for(int j = 0; j < n; j++)
                    cout << left[j] << " ";
                cout << endl;
                */
                for(int j = n - 1; j >= 0; j--) {
                    if(matrix[i][j] == '1')
                        right[j] = min(right[j], curr_right);
                    else {
                        curr_right = j;
                        right[j] = n;
                    }
                }
                /*
                for(int j = 0; j < n; j++)
                    cout << right[j] << " ";
                cout << endl;
                */
                for(int j = 0; j < n; j++)
                    maxArea = max(maxArea, height[j] * (right[j] - left[j]));
            
            }
            return maxArea;
        }

};



int main() {
    return 0;
}

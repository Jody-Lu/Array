class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int begin, end, mid;

        for(int i = 0; i < m; i++) {
            if(target > matrix[i][n - 1]) {
                continue;
            }

            if(target < matrix[i][0]) {
                return false;
            }

            begin = 0;
            end = n - 1;

            while(begin <= end) {
                mid = begin + (end - begin) / 2;
                if(matrix[i][mid] == target) {
                    return true;
                }
                if(matrix[i][mid] > target) {
                    end = mid - 1;
                }
                else {
                    begin = mid + 1;
                }
            }

        }
        return false;
    }
};
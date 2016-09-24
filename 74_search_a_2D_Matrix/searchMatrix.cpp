class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int begin = 0, end = matrix.size() - 1;
        while(begin <= end) {
            int mid = (begin + end) / 2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] > target) end = mid - 1;
            else begin = mid + 1;
        }
        int row = begin > 0? begin - 1 : 0;
        begin = 0;
        end = matrix[row].size() - 1;
        while(begin <= end) {
            int mid = (begin + end) / 2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid] > target) end = mid - 1;
            else begin = mid + 1;
        }
        if(matrix[row][begin] == target) return true;
        else return false;
    }
};
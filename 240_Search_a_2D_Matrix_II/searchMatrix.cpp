class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            if(target > matrix[i][n - 1]) continue;
            if(target < matrix[i][0]) return false;

            int left = 0, right = n - 1;
            while(left <= right) {
                int mid = (left + right) / 2;
                int val = matrix[i][mid];
                if(val == target) return true;
                if(val > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return false;
    }
};
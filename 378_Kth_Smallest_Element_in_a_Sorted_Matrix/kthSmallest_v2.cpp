class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        // O(n(lgn)^2)
        // corner case: when there are only one element in the matrix
        while(left < right) {
            int midv = (left + right) / 2;
            int count = 0;

            // O(nlgn)
            // number of element no bigger than midv
            for(int i = 0; i < n; i++) {
                vector<int>& row = matrix[i];
                count += upper_bound(row.begin(), row.end(), midv) - row.begin();
            }
            // mid is too small
            if(count < k) {
                left = midv + 1;
            }
            else {
                right = midv;
            }
        }

        return left;
    }
};
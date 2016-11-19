class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        // coner case: matrix = NULL
        if(matrix.size() != 0) {
            int n = matrix.size();
            int m = matrix[0].size();
            for(int i = 0; i < matrix.size(); i++) {
                vector<int> sum(m + 1, 0);
                for(int j = 1; j <= m; j++) {
                    sum[j] = sum[j - 1] + matrix[i][j - 1];
                }
                sums.push_back(sum);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(sums.size() == 0) { return 0; }
        int res = 0;

        for(int i = row1; i <= row2; i++) {
            res += (sums[i][col2 + 1] - sums[i][col1]);
        }

        return res;
    }

private:
    vector<vector<int> > sums;

};
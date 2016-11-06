class Solution {
    public:
        vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
            int mA = A.size();
            int nA = A[0].size();
            int mB = B.size();
            int nB = B[0].size();

            vector<vector<int> > res(mA, vector<int>(nB, 0));

            // multiply each element at a time
            for(int i = 0; i < mA; i++) {
                for(int k = 0; k < nA; k++) {
                    if(A[i][k] != 0) {
                        for(int j = 0; j < nB; j++) {
                            if(B[k][j] != 0) {
                                res[i][j] += A[i][k] * B[k][j];
                            }
                        }
                    }
                }
            }

            return res;
        }
};
#include <iostream>
#include <vector>

using namespace std;


// Naive
class Solution {
    public:
        vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
            int rA = A.size();
            int cA = A[0].size();
            int rB = B.size();
            int cB = B[0].size();

            vector<vector<int> > res(rA, vector<int>(cB, 0));

            for(int i = 0; i < rA; i++) {
                for(int j = 0; j < cB; j++) {
                    for(int k = 0; k < rB; k++) {
                        if(A[i][k] != 0 && B[k][j] != 0) {
                            res[i][j] = A[i][k] * B[k][j];
                        }
                    }
                }
            }

            return res;
        }
};

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
    public:
        int maxRotateFunction(vector<int>& A) {
            int n = A.size();
            if(n == 0) return 0;
            int sum = 0;
            for(int n:A) sum += n;
            vector<int> F(n, 0);

            // calculate F[0]
            for(int i = 0; i < n; i++)
                F[0] += i * A[i];

            int res = F[0];
            for(int k = 1; k < n; k++) {
                F[k] = F[k - 1] + sum - A[n - k] * n;
                res = max(res, F[k]);
            }

            return res;
        }
};

int main() {
    return 0;
}

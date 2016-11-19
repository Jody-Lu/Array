#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
            int m = A.size(), n = B.size();
            int l = (m + n + 1) >> 1;
            int r = (m + n + 2) >> 1;
            return (double)(findKth(A, 0, m - 1, B, 0, n - 1, l) + findKth(A, 0, m - 1, B, 0, n - 1, r)) / 2.0;
        }

    private:
        int findKth(vector<int>& A, int aL, int aR, vector<int>& B, int bL, int bR, int k) {
            if(aL > aR) return B[bL + k - 1];
            if(bL > bR) return A[aL + k - 1];

            int aMid = (aL + aR) / 2;
            int bMid = (bL + bR) / 2;


            if(A[aMid] <= B[bMid]) {
                /* k is smaller than the (m + n) / 2, where m = A.size, n = B.size() */
                /* Since A[aMid] <= B[bMid], just drop the right half of B. */
                if(k <= (aMid - aL) + (bMid - bL) + 1)
                    return findKth(A, aL, aR, B, bL, bMid - 1, k);
                /* k is larger than the (m + n) / 2, drop the left half of A. */
                /* Since drop the smaller part, we became finding k - (aMid - aL) -1. */
                else
                    return findKth(A, aMid + 1, aR, B, bL, bR, k - (aMid - aL) -1);
            }
            else {
                /* k is smaller than the (m + n) / 2, where m = A.size, n = B.size() */
                /* Since A[aMid] > B[bMid], just drop the right half of A. */
                if (k <= (aMid - aL) + (bMid - bL) + 1)
                    return findKth(A, aL, aMid - 1, B, bL, bR, k);
                /* k is larger than the (m + n) / 2, drop the left half of A. */
                /* Since drop the smaller part, we became finding k - (bMid - aL) -1. */
                else
                    return findKth(A, aL, aR, B, bMid + 1, bR, k - (bMid - bL) - 1);
            }
        }
};

int main() {
    return 0;
}

#include <iostream>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> VI;
typedef pair<int, VI> VIV;

struct comparator {
    bool operator() (VIV p1, VIV p2) {
        return p1.first > p2.first;
    }
};

class Solution {
    public:
        int kthSmallest(vector<vector<int> >& matrix, int k) {
            priority_queue<VIV, vector<VIV>, comparator> pq;

            for(int i = 0; i < matrix.size(); i++) {
                pq.push(VIV(matrix[i][0], VI(i, 1)));
            }

            while(k > 1) {
                VIV tmp = pq.top();
                int idx = tmp.second.second;
                int jdx = tmp.second.first;

                if(idx < matrix[jdx].size()) {
                    pq.pop();
                    pq.push(VIV(matrix[jdx][idx], VI(jdx, idx + 1)));
                }
                else {
                    pq.pop();
                }
                k--;
            }

            return pq.top().first;
        }
};
int main() {
    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        int numDistinct(string s, string t) {
            int n = s.size(), m = t.size();
            // DP[i][j]: number of subsequence aligning with s[0:i], t[0:j]
            vector<vector<int> > DP(m + 1, vector<int>(n + 1, 0));

            // DP[0][j] = 1
            for(int j = 0; j <= n; j++)
                DP[0][j] = 1;

            for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= n; j++) {
                    if(t[i - 1] != s[j - 1])
                        DP[i][j] = DP[i][j - 1];
                    else {
                        DP[i][j] = DP[i][j - 1] + DP[i - 1][j - 1];
                    }
                }
            }
            return DP[m][n];
        }
};

int main() {
    return 0;
}

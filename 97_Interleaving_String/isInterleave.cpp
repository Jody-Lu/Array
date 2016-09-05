#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int m = s1.size(), n = s2.size();
            // T[i][j]: whether s3[:i+j] is the interleaving of s1[:i] and s2[:j]
            if((m + n) != s3.size()) return false;
            vector<vector<bool> > T(m + 1, vector<bool>(n + 1, false));
            T[0][0] = true;

            // s2 is NULL.
            for(int i = 1; i <=m; i++)
                if(s1[i - 1] == s3[i - 1])
                    T[i][0] = T[i - 1][0];

            // s1 is NULL.
            for(int j = 1; j <= n; j++)
                if(s2[j - 1] == s3[j - 1])
                    T[0][j] = T[0][j - 1];

            for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= n; j++) {
                    if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] != s3[i + j - 1])
                        T[i][j] = T[i - 1][j];
                    else if(s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                        T[i][j] = T[i][j - 1];
                    else if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                        T[i][j] = T[i - 1][j] || T[i][j - 1];
                }
            }

            return T[m][n];
        }
};

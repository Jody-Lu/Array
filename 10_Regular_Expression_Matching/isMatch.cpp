#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int m = s.size(), n = p.size();
            vector<vector<bool> > T(m + 1, vector<bool>(n + 1, false));
            T[0][0] = true;

            for(int i = 1; i <= m; i++)
                T[i][0] = false;

            for(int j = 1; j <= n; j++)
                if(p[j - 1] == '')
        }
};

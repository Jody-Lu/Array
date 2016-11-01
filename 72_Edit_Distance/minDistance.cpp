#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
T[i][j] represents the minimum steps w1[:i] needs to transform to w2[:j].

First, we look the base case either w1's or w2's length is equal to 0. The minimum step must be the non-zero one's length (i.e., delete/add all its characters. ). So, we have:
 T[i][0] = i; // w2.size() == 0
 T[0][j] = j; // w1.size(0 == 0
Next, we see the normal case.
a. w1[i - 1] == w2[j - 1] means that we don't need to change any character at this moment, so T[i][j] = T[i - 1][j - 1].
b. w1[i - 1] != w2[j - 1] means that we need to change 1 character plus the min(T[i][j - 1], T[i - 1][j], T[i - 1][j - 1]).

Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
Delete word1[i - 1] and word1[0..i - 2] = word2[0..j - 1] (dp[i][j] = dp[i - 1][j] + 1 (for deletion));
Insert word2[j - 1] to word1[0..i - 1] and word1[0..i - 1] + word2[j - 1] = word2[0..j - 1] (dp[i][j] = dp[i][j - 1] + 1 (for insertion))

 */

class Solution {
    public:
        int minDistance(string w1, string w2) {
            int l1 = w1.size(), l2 = w2.size();
            // T[i][j]: the min step need change w1[:i] to w2[:j]
            vector<vector<int> > T(l1 + 1, vector<int>(l2 + 1, 0));

            // T[0][j] = j
            for(int j = 0; j <= l2; j++)
                T[0][j] = j;

            // T[i][0] = i
            for(int i = 0; i <= l1; i++)
                T[i][0] = i;

            for(int i = 1; i <= l1; i++) {
                for(int j = 1; j <= l2; j++) {
                    // w1, w2 have the same end at i, j.
                    // then, T[i][j] = T[i - 1][j - 1]
                    if(w1[i-1] == w2[j-1]) T[i][j] = T[i - 1][j - 1];
                    // w1, w2 have different end at i, j.
                    else
                        // T[i - 1][j - 1]:
                        T[i][j] = 1 + min(T[i - 1][j - 1], min(T[i - 1][j], T[i][j - 1]));
                }
            }
            return T[l1][l2];
        }
};

int main() {
    return 0;
}

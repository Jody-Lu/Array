#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            map<char, int> counts;
            int i = 0, I = 0, J = 0;
            int missing = t.size();
            for(int i = 0; i < t.size(); i++)
                counts[t[i]]++;

            for(int j = 0; j < s.size(); j++) {
                missing -= int(counts[s[j]] > 0);
                counts[s[j]]--;
                /* Find all the characters int t. */
                if(missing == 0) {
                    /* i goes ahead until meeting the first desired character. */
                    /* restoring the unrelated character. */
                    while(i < (j+1) && counts[s[i]] < 0) {
                        counts[s[i]]++;
                        i++;
                    }
                    /* checking whether s[i:j+1] is the new minWindow. */
                    if(!J || (j+1) - i <= J - I) {
                        I = i;
                        J = j + 1;
                    }
                }
            }
            return s.substr(I, J - I);
        }
};

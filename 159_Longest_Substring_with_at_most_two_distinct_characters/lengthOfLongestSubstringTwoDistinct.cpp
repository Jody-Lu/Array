#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128, 0);
        int n = s.size();
        int begin = 0, end = 0, counter = 0, res = 0;

        while(end < n) {
            if(++map[s[end++]] == 1) {
                counter++;
            }
            while(counter > 2) {
                if(--map[s[begin++]] == 0) {
                    counter--;
                }
            }
            res = max(res, (end - begin));
        }

        return res;
    }
};

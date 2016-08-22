#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.size() == 0 || s.size() == 1) return s.size();
            map<char, int> dict;
            int begin = 0, forward = 0, res = 0;

            /* Set all character unmarked. */
            for(int i = 0; i < s.size(); i++)
                dict[s[i]] = -1;

            for(int i = 0; i < s.size(); i++) {
                forward = i;
                /* If the char is unmarked, set it value to its index. */
                if(dict[s[i]] == -1)
                    dict[s[i]] = i;
                /* Meet duplicate char. */
                else {
                    /* Update res. */
                    res = max(res, forward - begin);
                    /* Set the values of chars before the duplicate one to -1 (unmarked). */
                    for(int j = begin; j < dict[s[i]]; j++)
                        dict[s[j]] = -1;
                    /* Update begin to the next of the duplicate one. */
                    begin = dict[s[i]] + 1;
                    dict[s[i]] = forward;
                }
            }
            return max(res, forward - begin + 1);
        }
};

int main() {
    string s = "abcabcbb";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}

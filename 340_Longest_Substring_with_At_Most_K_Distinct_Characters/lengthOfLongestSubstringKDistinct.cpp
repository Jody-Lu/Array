class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> map(128, 0);
        int begin = 0, end = 0, res = 0, n = s.size(), counter = 0;

        while(end < n) {
            /* Find one distinct */
            if(++map[s[end++]] == 1) {
                counter++;
            }
            /* Move k until the there is only k distinct numbers. */
            while(counter > k) {
                if(--map[s[begin++]] == 0) {
                    counter--;
                }
            }

            res = max(res, end - begin);
        }

        return res;

    }
};
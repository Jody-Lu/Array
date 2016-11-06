class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> map(128, 0);
        int begin = 0, end = 0, counter = 0, res = 0, n = s.size();

        while(end < n) {
            if(++map[s[end++]] == 1) {
                counter++;
            }
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
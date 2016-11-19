class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0;
        int num = 0;

        while(i < m && j < n) {
            if(isdigit(abbr[j])) {
                if(abbr[j] == '0') {
                    return false;
                }
                int val = 0;
                while(j < n && isdigit(abbr[j])) {
                    val = val * 10 + (abbr[j++] - '0');
                }
                i += val;
            }
            else if(word[i++] != abbr[j++]) {
                return false;
            }
        }

        return (i == m && j == n);

    }
};
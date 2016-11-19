class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        // corner case
        if(digits.size() == 0) { return res; }
        numMap = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s = "";
        letterCombinationsHelper(res, digits, s, 0);
        return res;
    }
private:
    vector<string> numMap;

    void letterCombinationsHelper(vector<string>& res, string& digits, string& s, int step) {
        if(step >= digits.size()) {
            res.push_back(s);
            return;
        }

        string chars = numMap[digits[step] - '0'];

        for(char c : chars) {
            s.push_back(c);
            letterCombinationsHelper(res, digits, s, step + 1);
            s.pop_back();
        }
    }
};
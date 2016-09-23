class Solution {
public:

    Solution() {
        num_dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        this -> digits = digits;
        dfs("", 0, res);
        return res;
    }

    void dfs(string s, int level, vector<string> &res) {
        if(s.size() == digits.size()) {
            res.push_back(s);
            return;
        }
        for(int i = 0; i < num_dict[digits[level] - '0'].size(); i++) {
            string tmp = s + (num_dict[digits[level] - '0'][i]);
            dfs(tmp, level + 1, res);
        }
    }
private:
    vector<string> num_dict;
    string digits;
};
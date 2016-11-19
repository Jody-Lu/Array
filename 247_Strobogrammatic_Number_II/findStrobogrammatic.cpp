class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        vector<char> digits;
        digits.push_back('0');
        digits.push_back('1');
        digits.push_back('6');
        digits.push_back('8');
        digits.push_back('9');
        string num = "";
        dfs(res, digits, num, n);
        return res;
    }

private:
    void dfs(vector<string>& res, vector<char>& digits, string& num, int n) {
        if(n == 0) {
            if(isValid(num)) {
                res.push_back(num);
            }
            return;
        }

        for(char d : digits) {
            num.push_back(d);
            dfs(res, digits, num, n - 1);
            num.pop_back();
        }
    }

    bool isValid(string& s) {
        int l, r, n = s.size();
        if(s.size() > 1 && s[0] == '0') { return false; }
        unordered_map<char, char> m = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        for(l = 0, r = n - 1; l <= r; l++, r--) {
            if(m[s[l]] != s[r]) { return false; }
        }

        return true;
    }
};
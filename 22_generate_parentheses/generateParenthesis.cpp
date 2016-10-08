class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, "", 0, 0, res);
        return res;
    }
private:
    void dfs(int n, string s, int nleft, int nright, vector<string>& res) {
        if(nleft == n && nright == n) {
            res.push_back(s);
            return;
        }

        if(nleft < n)
            dfs(n, s + '(', nleft + 1, nright, res);
        if(nright < nleft) // If nright > nleft, then it must be invalid
            dfs(n, s + ')', nleft, nright + 1, res);
    }
};

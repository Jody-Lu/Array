class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        dfs(res, k, n, vector<int>(), 0);
        return res;
    }
private:
    void dfs(vector<vector<int> > &res, int k, int n, vector<int> v, int begin) {
        if(k == v.size()) {
            res.push_back(v);
            return;
        }
        for(int i = begin; i < n; i++) {
            v.push_back(i + 1);
            dfs(res, k, n, v, i + 1);
            v.pop_back();
        }
    }
};
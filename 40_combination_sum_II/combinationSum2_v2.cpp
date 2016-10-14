class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(), candi.end());
        vector<vector<int> > res;
        dfs(res, target, candi, vector<int>(), 0);
        return res;
    }
private:
    void dfs(vector<vector<int> >& res,
             vector<int>& candi,
             vector<int> v,
             int begin,
             int remain) {

        if(remain == 0) {
            res.push_back(v);
            return;
        }
        for(int i = begin; i < candi.size(); i++) {
            if(candi[i] > remain) break;
            // do not count the same item more than one times in the same level
            if(i != begin && candi[i] == candi[i - 1])
                continue;
            v.push_back(candi[i]);
            dfs(res, candi, v, i + 1, remain - candi[i]);
            v.pop_back();
        }
    }
};

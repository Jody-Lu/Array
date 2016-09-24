class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(), candi.end());
        vector<vector<int> > res;
        dfs(res, target, candi, vector<int>(), 0);
        return res;
    }
private:
    void dfs(vector<vector<int> >& res, int remain, vector<int>& candi, vector<int> v, int begin) {
        if(remain == 0) {
            res.push_back(v);
            return;
        }
        for(int i = begin; i < candi.size(); i++) {
            if(candi[i] > remain) break;
            // do not count the same item more than one times in the same level 
            if(i && candi[i] == candi[i - 1] && i > begin) continue;
            v.push_back(candi[i]);
            dfs(res, remain - candi[i], candi, v, i + 1);
            v.pop_back();
        }
    }
};
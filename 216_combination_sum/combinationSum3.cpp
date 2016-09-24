#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> nums(arr, arr + 9);
        vector<vector<int> > res;
        dfs(res, n, k, nums, vector<int>(), 0);
        return res;
    }
private:
    void dfs(vector<vector<int> >& res, int remain, int k, vector<int>& candi, vector<int> v, int begin) {
        if(remain == 0 && v.size() == k) {
            res.push_back(v);
            return;
        }
        else if(v.size() == k) // will oversize 
            return;
        
        for(int i = begin; i < candi.size(); i++) {
            if(candi[i] > remain) break;
            v.push_back(candi[i]);
            dfs(res, remain - candi[i], k, candi, v, i + 1);
            v.pop_back();
        }
    }
};

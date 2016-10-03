#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int> > res;
            dfs(nums, 0, nums.size(), res);
            return res;
        }
    private:
        void dfs(vector<int> num, int i, int j, vector<vector<int> > &res) {
            if(i == j - 1) {
                res.push_back(num);
                return;
            }

            for(k = i; k < j; k++) {
                if(i != k && num[i] == num[k]) continue;
                swap(num[i], num[k]);
                dfs(num, i + 1, j, res);
            }
        }
};

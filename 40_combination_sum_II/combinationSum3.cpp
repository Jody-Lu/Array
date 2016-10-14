#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
            if(nums.size() == 0)
                return vector<vector<int> >();

            sort(nums.begin(), nums.end());
            
            vector<vector<int> > res;
            vector<int> instance;
            vector<bool> isUsed(nums.size(), false);
            dfs(nums, instance, res, 0, target, isUsed);
            return res;
        }
        int getSum(vector<int>& instance) {
            int sum = 0;
            for(int i = 0; i < instance.size(); i++)
                sum += instance[i];
            return sum;
        }
    private:
        void dfs(vector<int> num,
                 vector<int> instance,
                 vector<vector<int> >& res,
                 int start,
                 int target,
                 vector<bool>& usUsed) {
        
            if(getSum(instance) > target)
                return;

            if(getSum(instance) == target) {
                res.push_back(instance);
                return;
            }

            for(int i = start; i < num.size(); i++) {
                if(i != start && num[i] == num[i - 1] && isUsed[i - 1] == false)
                    continue;

                instance.push_back(num[i]);
                isUsed[i] = true;
                dfs(num, instance, res, start + 1, target, isUsed);
                isUsed[i] = false;
                instance.pop_back();
            }

        }
};

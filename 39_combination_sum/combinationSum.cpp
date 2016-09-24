#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candi, int target) {
        sort(candi.begin(), candi.end());
        vector<vector<int> > res;
        dfs(res, target, candi, vector<int>());
        return res;
    }
private:
    void dfs(vector<vector<int> >&  res, int remain, vector<int>& candi, vector<int> v) {
        if(remain == 0) {
            res.push_back(v);
            return;
        }

        for(int i = 0; i < candi.size() && candi[i] <= remain; i++) {
            if(!v.empty() && candi[i] < v.back())
                continue;
            else {
                v.push_back(candi[i]);
                dfs(res, remain - candi[i], candi, v);
                v.pop_back();
            }
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;
	vector<vector<int> > result;
	int target = 7;
	int arr[] = {2, 3, 4, 7};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.combinationSum(nums, target);
	//cout << result.size() << endl;

	for(int j = 0; j < result.size(); ++j)
	{
		for(int i = 0; i < result[j].size(); ++i)
		{
			cout << result[j][i] << " ";
		}
		cout << endl;
	}

	//cout << result[0].size() << endl;
	return 0;
}

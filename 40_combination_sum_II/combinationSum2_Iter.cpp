#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
            vector<vector<vector<int> > > combinations(target + 1, vector<vector<int> >);
            
            // base case
            combinations.push_back(vector<vector<int> >());

            for(auto &score : candi) {
                for(int j = score; j <= target; j++) {
                    if(combinations[j - score].size() > 0) {
                        auto &tmp = combinations[j - score];
                        for(auto &s : tmp) {
                            
                        }
                    }
                }
            }
        }

};

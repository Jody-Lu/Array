#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candi, int target) {
        // combinations[i]: value i's combination methods.
        vector<vector<vector<int> > > combinations(target + 1, vector<vector<int> >());
        // base case: value 0's combination []
        combinations[0].push_back(vector<int>());

        for(auto& score : candi) {
            for(int j = score; j <= target; j++) {
                if(combinations[j - score].size() > 0) {
                    /* put score to all combinations of combinations[j - score]*/
                    auto tmp = combinations[j - score];
                    for(auto& s : tmp) {
                        s.push_back(score);
                    }
                    /* Insert the answer to combinations[i]. */
                    combinations[j].insert(combinations[j].end(), tmp.begin(), tmp.end());
                }
            }
        }
        return combinations[target];
    }
};

int main() {
    return 0;
}

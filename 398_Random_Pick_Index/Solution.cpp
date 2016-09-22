#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
	public:
    	Solution(vector<int> nums) {
            for(int i = 0; i < nums.size(); i++)
                mapping[nums[i]].push_back(i);
    	}

    	int pick(int target) {
            vector<int> s = mapping[target];
            int n = s.size();
            int res = s[0];
            for(int i = 1; i < n; i++) {
                int j = rand() % (i + 1);
                if(j == 0) res = s[i];
            }
            return res;
    	}
    private:
        map<int, vector<int> > mapping;
};

int main() {
    return 0;
}

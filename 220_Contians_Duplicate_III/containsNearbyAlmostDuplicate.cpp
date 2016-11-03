#include <iostream>
#include <vector>
#include <set>

using namespace std;

// set.lower_bound(val) --> returns the iterator that points to at least val
// sert.upper_bound(val) --> returns the iterator that points to at most val

class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            set<int> window;
            for(int i = 0; i < nums.size(); i++) {
                if(i > k) { window.erase(nums[i - k - 1]); }

                auto pos = window.lower_bound(nums[i] - t);

                if(pos != window.end() && (*pos - nums[i]) <= t) {
                    return true;
                }

                window.insert(nums[i]);
            }
            return false;
        }
};

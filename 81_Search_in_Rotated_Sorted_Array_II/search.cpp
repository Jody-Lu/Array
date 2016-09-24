/* Finding rp would be a problem*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int rp = 1;
            while(rp < nums.size() && nums[rp] >= nums[rp - 1])
                rp++;
            int begin = 0, end = nums.size() - 1;
            while(begin <= end) {
                int mid = begin + (end - begin) / 2;
                int realmid = (mid + rp) % nums.size();
                if(nums[realmid] == target) return true;
                if(nums[realmid] > target) end = mid - 1;
                else begin = mid + 1;
            }
            return false;
        }
}; 

int main() {
    int arr[] = {2, 2, 2};
    vector<int> nums(arr, arr + 3);
    int target = 0;
    Solution sol;
    cout << sol.search(nums, target) << endl;
}


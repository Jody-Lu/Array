#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
    	int search(vector<int>& nums, int target) {
            int begin = 0, end = nums.size() - 1;
            /* Find rotating point. */
            while(begin < end) {
                int mid = begin + (end - begin) / 2;
                if(nums[mid] > nums[end]) begin = mid + 1;
                else end = mid;
            }
            int rp = begin;
            begin = 0;
            end = nums.size() - 1;
            cout << rp << endl;
            while(begin <= end) {
                int mid = begin + (end - begin) / 2;
                /* It's the point to find realmid. */
                /* The original mid is nums[mid]. If we shift rp, the mid
                   also be shifted rp --> (mid + rp) % nums.size(). */
                int realmid = (mid + rp) % nums.size();
                if(nums[realmid] == target) return realmid;
                if(target > nums[realmid]) begin = mid + 1;
                else end = mid - 1;
            }
            return -1;
    	}
};

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums(arr, arr + 7);
    int target = 4;
    Solution sol;
    sol.search(nums, target);
}

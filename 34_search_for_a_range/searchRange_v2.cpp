#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int begin = 0, end = nums.size() - 1;
            vector<int> res(2, -1);
            
            // search for the left border.
            while(begin < end) {
                int mid = begin + (end - begin) / 2;
                if(nums[mid] < target) begin = mid + 1;
                else end = mid;
            }
            if(nums[begin] != target) return res;
            else res[0] = begin;

            // search for the right border.
            end = nums.size() - 1;
            while(begin < end) {
                int mid = begin + (end - begin) / 2 + 1;
                if(nums[mid] > target) end = mid - 1;
                else begin = mid;
            }
            res[1] = end;
            return res;   
        }
        int bSearch(vector<int>& nums, int target) {
            int begin = 0, end = nums.size() - 1;
            while(begin <= end) {
                int mid = (begin + end) / 2;
                //if(nums[mid] == target) return mid;
                if(nums[mid] < target) begin = mid + 1;
                else end = mid - 1;
            }
            cout << begin << " " << end << endl;
            return begin;
        }
};

int main() {
    int arr[] = {1, 5, 7, 8, 10};
    vector<int> nums(arr, arr + 5);
    int target = 8;
    Solution sol;
    sol.bSearch(nums, target);
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int begin = 0, end = nums.size() - 1, res = -1;
            while(begin <= end) {
                int mid = begin + (end - begin) / 2;
                if(nums[mid] == target) {
                    res = mid;
                    break;
                }
                if(nums[mid] > target) end = mid - 1;
                else begin = mid + 1;
            }
            if(res == - 1) res = begin;
            if(nums[res] != target) return vector<int>{-1, -1};
            int tmp = res;
            while(tmp < nums.size() && nums[tmp] == target) tmp++;
            while(res > -1 && nums[res] == target) res--;
            return vector<int>{res + 1, tmp - 1};
        }
};

int main() {
    return 0;
}

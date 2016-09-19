#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return false;
        vector<int> LIS;
        LIS.push_back(nums[0]);
        for(int i = 0; i < n; i++) {
            if(nums[i] > LIS.back()) { 
                LIS.push_back(nums[i]);
                if(LIS.size() == 3) return true;
            }
            else {
                int begin = 0, end = LIS.size() - 1;
                while(begin <= end) {
                    int mid = begin + (end - begin) / 2;
                    if(LIS[mid] == nums[i]) {
                        begin = mid;
                        break;
                    }
                    if(LIS[mid] > nums[i]) end = mid - 1;
                    else begin = mid + 1;
                }
                LIS[begin] = nums[i];
            }
        }
        return false;
    }
};
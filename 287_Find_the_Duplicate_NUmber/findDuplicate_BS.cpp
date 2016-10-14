#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int begin = 1, end = nums.size() - 1;
            while(begin < end) {
                int mid = begin + (end - begin)/2;
                int count = 0;
                for(int i = 0; i < nums.size(); i++)
                    if(nums[i] <= mid)
                        count++;
                if(count > mid) end = mid;
                else begin = mid + 1;
            }
            return begin;
        }
};

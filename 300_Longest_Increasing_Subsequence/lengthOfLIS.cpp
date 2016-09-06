#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int N = nums.size();
            if(N == 0) return 0;
            vector<int> LIS;
            LIS.push_back(nums[0]);

            for(int i = 1; i < N; i++) {
                if(nums[i] > LIS.back())
                    LIS.push_back(nums[i]);
                else {
                    int begin = 0, end = LIS.size() - 1;
                    while(begin <= end) {
                        int mid = begin + (end - begin) / 2;
                        if(nums[i] == LIS[mid]) {
                            begin = mid;
                            break;
                        }
                        if(nums[i] > LIS[mid])
                            begin = mid + 1;
                        else
                            end = mid - 1;
                    }
                    LIS[begin] = nums[i];
                }
            }
            return LIS.size();
        }
};

int main() {
    return 0;
}

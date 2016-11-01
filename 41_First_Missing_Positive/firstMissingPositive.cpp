#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int n = segreate(nums) + 1;
            for(int i = 0; i < n; i++) {
                if((abs(nums[i]) - 1) < n && nums[abs(nums[i]) - 1] > 0) {
                    nums[abs(nums[i]) - 1] *= -1;
                }
            }


            for(int i = 0; i < n; i++) {
                if(nums[i] > 0) {
                    return (i + 1);
                }
            }
            return (n + 1);
        }
    private:
        // [+++++-----]
        int segreate(vector<int>& nums) {
            int n = nums.size();
            int j = n - 1;
            for(int i = n - 1; i >= 0; i--) {
                if(nums[i] <= 0) {
                    swap(nums[i], nums[j]);
                    j--;
                }
            }
            return j;

        }
};

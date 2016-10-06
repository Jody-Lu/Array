#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int splitArray(vector<int> &nums, int m) {
            int N = nums.size();
            int Sum = 0, Max = 0;
            /* The answer must be between max value of nums and sum of nums. 
               So, we can use binary search to find the answer between these two values.
               Let l = Max, r = Sum and mid = (l + r) / 2
               We discuss two cases:
               1. The value we choose is too small. i.e., 
                  we can divide more than m subarrays with the maximum sum smaller than mid.
                  =====> l = mid + 1
               2. The value we choose is too large. i.e., 
                  we can divide less than m subarrays with the maximum sum smaller than mid.
                  =====> r = mid - 1
               Then, we can find the answer.
            */
            /* Find the max and sum of nums. */
            for(int i = 0; i < N; i++) {
                Sum += nums[i];
                Max = max(Max, nums[i]);
            }

            /* Binary search to find the answer.*/
            int begin = Max, end = Sum;
            while(begin <= end) {
                int mid = begin + (end - begin) / 2;
                if(!isValid(mid, nums, m))
                    begin = mid + 1;
                else
                    end = mid - 1;
            }
            return begin;
        }
    private:
        bool isValid(int target, vector<int>& nums, int m) {
            int num = 0, count = 0;
            for(int i = 0; i < nums.size(); i++) {
                num += nums[i];
                if(num > target) { // go to another subarray
                    num = nums[i];
                    if(++count >= m)
                        return false;
                }
            }
            return true;
        }
};


int main() {
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            return _mergeSort(nums, 0, nums.size() - 1);    
        }
    private:
        int _mergeSort(vector<int>& nums, int begin, int end) {
            int mid = (begin + end) / 2;
            int left, right, rMax = nums[mid + 1], lMax = nums[mid];
            if(begin < end) {
                left = _mergeSort(nums, begin, mid);
                right = _mergeSort(nums, mid+1, end);
            }
            else return nums[begin];
            
            // Merge the result: compare left, right, and middle. 
            int tmp = 0;
            for(int i = mid; i >= begin; i--) {
                tmp += nums[i];
                if(tmp > lMax) lMax = tmp;
            }
            tmp = 0;
            for(int i = mid + 1; i <= end; i++) {
                tmp += nums[i];
                if(tmp > rMax) rMax = tmp;
            }
            return max(max(left, right), lMax+rMax);
        }
};

int main() {
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(arr, arr + 9);
    Solution sol;
    cout << sol.maxSubArray(nums) << endl;
}

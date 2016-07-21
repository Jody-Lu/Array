#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        while (right < len) {
            while (sum < s && right < len) {
                sum += nums[right++];
            }
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == len + 1 ? 0 : res;
    }
};

int main()
{
	Solution sol;
	int result;
	int s = 7;
	int arr[] = {2, 3, 1, 2, 4, 3};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	//cout << nums.size() << endl;
	result = sol.minSubArrayLen(s, nums);
	cout << result << endl;

}
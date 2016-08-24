#include <iostream>
#include <vector>

using namespace std;

// come from linked list with circle.
/* 
Since all element are between 1 ~ n (inclusive), 
We can think them as node of linked list and each
node points to nums[its value]. 
For example, node 0 points to node nums[0].
So, we know that the duplicate term must be the entry of
the circle.
 
*/
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while(slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = nums[0];
            while(slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
};

int main() {
    Solution sol;
    int arr[] = {1, 2, 3, 3};
    vector<int> nums(arr, arr + 4);
    cout << sol.findDuplicate(nums) << endl;
}

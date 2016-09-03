#include <deque>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ans;
            deque<int> dq;
            for(int i = 0; i < nums.size(); i++) {
                // move to next window, remove the item in last window.
                if(!dq.empty() && dq.front() == i - k) dq.pop_front();
                // if next is bigger one, remove all the smaller ones.
                while(!dq.empty() && nums[dq.back()] < nums[i])
                    dq.pop_back();
                dq.push_back(i);
                // once i >= k - 1, start saving the biggest one in the window.
                if(i >= k - 1) ans.push_back(nums[dq.front()]); 
            }
            return ans;
        }
};


int main() {
    return 0;
}

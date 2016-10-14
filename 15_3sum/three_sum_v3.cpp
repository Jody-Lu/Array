#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &nums)
        {
            int n = nums.size();
            int target = 0, last = n - 1;
            vector<vector<int> > res;
            if(n < 3) return res;

            sort(nums.begin(), nums.end());

            /* Fixed i's value and use j and k two pointer to find the answer. */
            /* Be careful about the duplicate items. */
            for(int i = 0; i < n - 2; i++)
            {
                int j = i + 1;
                if(i > 0 && nums[i] == nums[i - 1])
                    continue;
                int k = last;
                while(j < k)
                {
                    if((nums[i] + nums[j] + nums[k]) < target)
                    {
                        j++;
                        while(nums[j] == nums[j - 1] && j < k)
                            j += 1;
                    }
                    else if((nums[i] + nums[j] + nums[k]) > target)
                    {
                        k--;
                        while(nums[k] == nums[k + 1] && j < k)
                            k--;
                    }
                    else
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                        j += 1;
                        k -= 1;
                        while(nums[j] == nums[j - 1] && nums[k] == nums[k + 1] && j < k)
                            j += 1;
                    }
                }
            }
            return res;

        }
};

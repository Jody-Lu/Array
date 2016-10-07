class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int res = nums[n - 1] + nums[n - 2] + nums[n - 3];
            if(n == 3) return res;
            int remain = abs(target - res);

            for(int i = 0; i < n - 2; i++)
            {
                int j = i + 1, k = n - 1;
                while(j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == target) return sum;
                    if(abs(sum - target) <= remain)
                    {
                        remain = abs(sum - target);
                        res = sum;
                        if(sum < target)
                            j++;
                        else
                            k--;
                    }
                    else
                    {
                        if(abs(target - (nums[i] + nums[j + 1] + nums[k])) > \
                           abs(target - (nums[i] + nums[j] + nums[k - 1])))
                        {
                            k--;
                        }
                        else j++;
                    }
                }
            }
            return res;
        }
};
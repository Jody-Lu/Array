#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
	    int result = INT_MIN, f = 0;
	    for(int i = 0; i < nums.size(); ++i)
	    {
	    	f = max(f + nums[i], nums[i]); // either concatenate or choosing nums[i] 
            result = max(result, f); 
	    }

	    return result;
	}
    int maxSubArrayR(vector<int>& nums)
    {
        int res = INT_MIN, f = 0;
        int left = 0, right = 0, l = 0, r = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(f + nums[i] > nums[i])
            {
                f = (f + nums[i]);
                r = i;
            }
            else
            {
                f = nums[i];
                l = i;
            }

            if(f > res)
            {
                res = f;
                left = l;
                right = r;
            }
        }
        cout << left << " " << right << endl;
        for(int i = left; i <= right; i++)
            cout << nums[i] << " ";
        cout << endl;
        return res;
    }
};

int main()
{
	Solution sol;
	int result;
	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.maxSubArrayR(nums);
	cout << result << endl;
}

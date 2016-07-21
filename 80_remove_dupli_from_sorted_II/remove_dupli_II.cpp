#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size();
        if (len < 2) return len;
        int ret = 2;

        for (int i = 2; i < len; i++)
        {
            if (nums[i] != nums[ret - 2])
            {
                nums[ret++] = nums[i];
            }
        }

        nums.erase(nums.begin() + ret, nums.end());
        return ret;
    }
    
	/*
	int removeDuplicates(vector<int>& nums)
	{
		if(nums.size() == 0) return 0;

		if(nums.size() == 1) return 1;

		int repeat_times = 1;

		vector<int>::iterator first = nums.begin();
		vector<int>::iterator last = nums.end();
		vector<int>::iterator result = first;

		if(*first == *(last - 1))
		{
			nums.erase(first += 2, last);
			return nums.size();
		}

		while(++first != last)
		{
			if(*first == *result && *first != *(first + 1))
			{
				++result;
				*result = *first;
			}
			else if(!(*first == *result))
			{
				*(++result) = *first;
			}
		}


		nums.erase(++result, last);

		return nums.size();
	}
	*/

};

int main()
{
	int result;
	int arr[] = {-1, 0, 0, 0, 0, 3, 3};
	Solution sol;
	vector<int> nums(arr, arr + (sizeof(arr)/sizeof(*arr)));
	result = sol.removeDuplicates(nums);

	for(vector<int>::iterator it = nums.begin();
		it != nums.end();
		it++)
	{
		cout << *it << " ";
	}

	cout << endl;
	//cout << endl << result << endl;


}
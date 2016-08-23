#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int i_1 = m - 1, i_2 = n - 1, icur = m + n - 1;
		while(i_1 >= 0 && i_2 >= 0)
		{
			// count from back
            nums1[icur--] = nums1[i_1] >= nums2[i_2]? nums1[i_1--] : nums2[i_2--];
		}
		while(i_2 >= 0)
		{
			nums1[icur--] = nums2[i_2--];
		}
	}
};

int main()
{
	Solution sol;
	int arr_1[] = {1, 2, 7, 8, 0, 0, 0};
	vector<int> nums1(arr_1, arr_1 + (sizeof(arr_1) / sizeof(*arr_1)));

	int arr_2[] = {3, 4, 5};
	vector<int> nums2(arr_2, arr_2 + (sizeof(arr_2) / sizeof(*arr_2)));
	sol.merge(nums1, 4, nums2, nums2.size());

	for(vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}

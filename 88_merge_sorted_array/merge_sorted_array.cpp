#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1, idx = m + n - 1;
        while(idx1 >= 0 && idx2 >= 0)
            nums1[idx--] = (nums1[idx1] > nums2[idx2])? nums1[idx1--] : nums2[idx2--];
        // idx1 < 0 --> the remaining elements are nums2's.
        // idx2 < 0 --> the remaining elements are nums1's (they are already in there position). 
        while(idx2 >= 0) 
            nums1[idx--]= nums2[idx2--];
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

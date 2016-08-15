#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;
// Hash Table Solution
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            vector<int> res;
            int e1 = (int)nums1.size(), e2 = (int)nums2.size();
            int s1 = 0, s2 = 0;
            while(s1 < e1 && s2 < e2)
            {
                if(nums1[s1] == nums2[s2])
                {
                    res.push_back(nums1[s1]);
                    s1++;
                    s2++;
                }
                else if (nums1[s1] > nums2[s2])
                {
                    s2++;
                }
                else
                    s1++;

            }
            return res;
        }
};

int main()
{
    Solution sol;
    int arr1[] = {1, 2, 2, 3, 5};
    vector<int> nums1(arr1, arr1 + 5);
    int arr2[] = {1, 2, 2, 4};
    vector<int> nums2(arr2, arr2 + 4);
    vector<int> result;
    result = sol.intersect(nums1, nums2);
    for(vector<int>::iterator it = result.begin();
        it != result.end();
        it++)
    {
        cout << *it <<" ";
    }
    cout << endl;
    return 0;
}

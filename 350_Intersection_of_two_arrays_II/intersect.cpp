#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            map<int, int> mapping;
            vector<int> result;
            for(int i = 0; i < nums1.size(); i++)
            {
                map<int, int>::iterator it = mapping.find(nums1[i]);
                if(it != mapping.end())
                    mapping[nums1[i]]++;
                else
                    mapping[nums1[i]] = 1;
            }

            for(int i = 0; i < nums2.size(); i++)
            {
                map<int, int>::iterator it = mapping.find(nums2[i]);
                if(it != mapping.end())
                {
                    if(mapping[nums2[i]] > 0)
                    {
                        result.push_back(nums2[i]);
                        mapping[nums2[i]]--;
                    }
                    else
                        continue;
                }
            }
    
            /*
            for(map<int, int>::iterator it = mapping.begin();
                it != mapping.end();
                it++)
            {
                cout << it -> first << " " << it -> second << endl;
            }
            */
            return result; 

            
        }
};

int main()
{
    Solution sol;
    int arr1[] = {1, 2, 2, 3, 5};
    vector<int> nums1(arr1, arr1 + 5);
    int arr2[] = {1, 2, 2};
    vector<int> nums2(arr2, arr2 + 3);
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

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;
// Hash Table Solution
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> dict;
            vector<int> res;
            for(int i = 0; i < (int)nums1.size(); i++)
                dict[nums1[i]]++;
            for(int i = 0; i < (int)nums2.size(); i++)
            {

                //if(--dict[nums2[i]] >= 0)
                // Based on C++ map mechanism, if a key is not exist, access the key 
                //will assign a default value to the key. so if you simply test if 
                //map[key] is 0 or not by using "if (map[key] == 0)" without 
                //testing if the key is in the map.
                if(dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0)
                    res.push_back(nums2[i]);
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

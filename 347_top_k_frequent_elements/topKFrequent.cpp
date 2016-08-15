#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>

using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

class Solution {
	public:
    	vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> dict;
            vector<int> res;
            for(int i = 0; i < nums.size(); ++i)
            {
                dict[nums[i]]++;
            }
            vector<pair<int, int> > map(dict.begin(), dict.end());
            sort(map.begin(), map.end(), less_second<int, int>());

            for(int i = 0; i < k; i++)
            {
                res.push_back(map[i].first);
            }
            return res;

    	}
};

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 2, 3, 4, 4, 5};
    vector<int> nums(arr, arr+10);
    int k = 3;
    Solution sol;
    vector<int> res;
    res = sol.topKFrequent(nums, k);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;

}

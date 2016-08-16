#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

class Solution {
	public:
    	vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> dict;
            vector<int> res;
            for(int i = 0; i < nums.size(); ++i)
            {
                dict[nums[i]]++;
            }
            priority_queue<pair<int, int>> pq;
            for(auto it = dict.begin(); it != dict.end(); it++)
            {
                pq.push(make_pair(it->second, it->first));
                if(pq.size() > (int)dict.size() - k)
                {
                    res.push_back(pq.top().second);
                    pq.pop();
                }
            }
            return res;
    	}
};

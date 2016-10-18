#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> record(nums.begin(), nums.end());
            int res = 1;
            for(int n: nums) {
                if(record.find(n) == record.end()) continue;
                record.erase(n);
                int prev = n - 1;
                int next = n + 1;
                while(record.find(prev) != record.end()) record.erase(prev--);
                while(record.find(next) != record.end()) record.erase(next++);
                res = max(res, next - prev - 1);
            }
            return res;
        }
};

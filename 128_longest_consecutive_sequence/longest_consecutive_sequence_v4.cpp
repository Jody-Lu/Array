#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 1;
        unordered_set<int> record(nums.begin(), nums.end());
        id.resize(nums.size());
        
        for(int i = 0; i < nums.size(); i++) {
            id[i] = i;
        }
        
        for(int n : nums) {
            if(record.find(n) == record.end()) { continue; }
            int prev = n - 1;
            int next = n + 1;
            while(record.find(prev) != record.end() && find(n) != find(prev)) { 
                unions(n, prev);
                prev--;
            }
            while(record.find(next) != record.end() && find(n) != find(next)) { 
                unions(n, next);
                next++;
            }
            res = max(res, (next - prev - 1));
        }
        
        return res;
    }

private:
    vector<int> id;
    
    void unions(int p, int q) {
        int x = find(p);
        int y = find(q);
        if(x != y) {
            id[x] = y;
        }
    }
    
    int find(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        
        return i;
    }

};

int main() {
    Solution sol;
    int arr[12] = {9,1,-3,2,4,8,3,-1,6,-2,-4,7};
    vector<int> nums(arr, arr + 12);
    cout << sol.longestConsecutive(nums) << endl;
}

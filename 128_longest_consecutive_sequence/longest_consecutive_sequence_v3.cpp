#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class UF {
public:
    UF(int N): count(N) {
        for(int i = 0; i < N; i++) {
            id.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int p) {
        while(p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int getCount() {
        return count;
    }

    void connect(int p, int q) {
        int i = find(p);
        int j = find(q);

        if(i == j)
            return;
        if(rank[i] < rank[j])
            id[i] = j;
        else if(rank[i] > rank[j])
            id[j] = i;
        else {
            id[j] = i;
            rank[i] += 1;
        }
        count--;
    }
    void printId() {
        for(int n : id)
            cout << n << " ";
        cout << endl;
    }

private:
    vector<int> id;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record(nums.begin(), nums.end());
        UF uf(nums.size());
        int res = 1;
        for(int n : nums) {
            if(record.find(n) == record.end()) continue;
            else {
                int prev = n - 1;
                int next = n + 1;
                while(record.find(prev) != record.end()) uf.connect(n, prev--);
                while(record.find(next) != record.end()) uf.connect(n, next++);
                res = max(res, next - prev - 1);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int arr[12] = {9,1,-3,2,4,8,3,-1,6,-2,-4,7};
    vector<int> nums(arr, arr + 12);
    cout << sol.longestConsecutive(nums) << endl;
}

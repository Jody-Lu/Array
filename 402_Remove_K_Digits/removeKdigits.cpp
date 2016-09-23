#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string removeKdigits(string num, int k) {
            int len = num.size();
            if(len == k) return "0";
            k = len - k;
            int beg_idx = 0;
            string res;
            while(k) {
                int min_idx = beg_idx;
                for(int i = beg_idx; i <= len - k; i++)
                    if(num[min_idx] > num[i])
                        min_idx = i;

                if(!res.empty() || num[min_idx] != '0' || k == 1)
                    res.push_back(num[min_idx]);

                beg_idx = min_idx + 1;
                k--;
            }
            return res;
        }
};

int main() {
    Solution sol;
    string num = "10200";
    int k = 1;
    cout << sol.removeKdigits(num, k) << endl;
}

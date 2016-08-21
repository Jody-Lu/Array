#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int titleToNumber(string s) {
            int res = 0;
            int pow = 1;
            int idx = 0;
            while(idx < s.size()) {
                res += pow * (int(s[idx]) - 64);
                pow *= 26;
                idx++;
            }
            return res;
        }
};

int main() {
    string s = "AAA";
    Solution sol;
    cout << sol.titleToNumber(s) << endl;
}

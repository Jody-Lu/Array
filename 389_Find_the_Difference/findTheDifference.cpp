#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        char findTheDifference(string s, string t) {
            int sl = s.size(), tl = t.size();
            int res = s[0];
            for(int i = 1; i < sl; i++)
                res ^= s[i];
            for(int i = 0; i < tl; i++)
                res ^= t[i];
            return res;

        }
};

int main() {
    string s = "abcd";
    string t = "abcde";
    Solution sol;
    cout << sol.findTheDifference(s, t) << endl;

}

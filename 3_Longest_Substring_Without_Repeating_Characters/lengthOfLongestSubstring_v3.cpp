#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128, 0);
        int begin = 0, end = 0, n = s.size(), res = 0, counter = 0;

        while(end < n) {
            if(++map[s[end++]] > 1) {
                counter++;
            }

            while(counter > 0) {
                if(--map[s[begin++]]) {
                    counter--;
                }
            }

            res = max(res, end - begin);
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s = "bbbbb";
    cout << sol.lengthOfLongestSubstring(s) << endl;

}

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
    public:
        int longestSubstring(string s, int k) {
            int N = s.size();
            int maxL = 0;
            if(k > N) return 0;
            for(int len = N; len >= k; len--) {
                for(int left = 0; left < (N - len + 1); left++) {
                    int right = left + len;
                    map<char, int> count;
                    for(int m = left; m < right; m++) {
                        count[s[m]]++;
                    }
                    map<char, int>::iterator it;
                    for(it = count.begin(); it != count.end(); it++)
                        if(it -> second < k) break;
                    if(it == count.end()) return len;
                }
            }

            return 0;
        }
};

int main() {
    string s = "ababbc";
    int k = 2;
    Solution sol;
    cout << sol.longestSubstring(s, k) << endl;
    return 0;
}

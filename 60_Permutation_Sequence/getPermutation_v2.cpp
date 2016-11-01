#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        string res = "";
        for(int i = 1; i <= n; i++) {
            s.append(to_string(i));
        }
        dfs(res, s, k, 0);
        return res;
    }
    void dfs(string& res, string& s, int k, int startIndex) {
        if(startIndex >= s.size()) {
            k--;
        }
        
        if(k == 0) {
            res = s;
        }

        if(k < 0) {
            return;
        }

        for(int i = startIndex; i < s.size(); i++) {
            swap(s[i], s[startIndex]);
            dfs(res, s, k, startIndex + 1);
            swap(s[i], s[startIndex]);
        }
    }
};

int main() {
    Solution sol;
    int n = 3, k = 3;
    cout << sol.getPermutation(n, k) << endl;
}

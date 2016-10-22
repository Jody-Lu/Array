#include <iostream>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if(m > n) return isOneEditDistance(t, s);
        if(n - m > 1) return false;
        bool mismatch = false;

        for(int i = 0; i < m; i++) {
            if(s[i] != t[i]) {
                if(m == n) s[i] = t[i];
                else s.insert(i, 1, t[i]);
                mismatch = true;
                break;
            }
        }
        // (mismatch && s == t): same after modification
        // (!mismatch && n - m == 1): ex: aa, aab
        return (mismatch && s == t) || (!mismatch && n - m == 1);
    }
};

int main() {
    cout << tolower('c') << endl;
    cout << 'c' - 'a' << endl;
}


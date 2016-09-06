#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool isdigit(char c) {
    return ( '0' <= c && c <= '9' );
}

class Solution {
    public:
        int calculate(string s) {
            int idx = 0;
            int res = 0;
            int N = s.size();
            string rp = "(+-";
            vector<int> sign(2, 1);

            while(idx < N) {
                char x = s[idx];
                if(isdigit(x)) {
                    int start = idx;
                    while(idx < N && isdigit(s[idx])) idx += 1;
                    res += sign.back() * stoi(s.substr(start, idx - start));
                    sign.pop_back();
                    continue;
                }
                else if(rp.find(x) != string::npos)
                    sign.push_back(sign.back() * ((x == '-')? -1 : 1));
                else if(x == ')')
                    sign.pop_back();
                idx++;
            }
            return res;
        }
};

int main() {
    string s = "(1+(4+5+2)-3)+(6+8)";
    Solution sol;
    cout << sol.calculate(s) << endl;

}

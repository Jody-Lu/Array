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
            stack<int> vals;
            stack<char> ops;

            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '(') continue;
                else if(s[i] == '+' || s[i] == '*') ops.push(s[i]);
                else if(s[i] == ')') {
                    char op = ops.top();
                    ops.pop();
                    if(op == '+') {
                        int val = vals.top();
                        vals.pop();
                        val += vals.top();
                        vals.pop();
                        vals.push();
                    }
                }
            }
        }
};

int main() {
    string s = "(1+(4+5+2)-3)+(6+8)";
    Solution sol;
    cout << sol.calculate(s) << endl;

}

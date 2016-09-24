#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
	    vector<string> generateParenthesis(int n) {
            vector<string> res;
            if(n == 0) return res;

            string s(n, '(');
            s.append(n, ')');

            while(true) {
                auto l = n, r = n;
                res.push_back(s);
                while(true) {
                    if(s.back() == ')') --r;
                    else if(l < r + 2) --l;
                    else break;
                    s.pop_back();
                    if(s.empty()) return res;
                }
                s.back() = ')'; // that's why n - (r + 1)
                s.append(n - (l - 1), '('); // replace one '(' with ')'
                s.append(n - (r + 1), ')');
            }
	    }
};

int main() {
    return 0;
}

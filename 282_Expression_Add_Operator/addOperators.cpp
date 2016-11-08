#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> addOperators(string num, int target) {
            vector<string> res;
            if(num.empty()) { return res; }

            for(int i = 0; i <= num.size(); i++) {
                string s = num.substr(0, i);
                long cur = stol(s);
                if(to_string(cur).size() != s.size()) { continue; }
                addOperatorHelper(res, num, target, s, i, cur, cur, '#');
            }

            return res;
        }

    private:
        void addOperatorHelper(vector<string>& res, string& num, int target, string cur, int pos, long cv, long pv, char op) {
            if(pos == num.size() && cv == target) {
                res.push_back(cur);
            }
            else {
                for(int i = pos + 1; i <= num.size(); i++) {
                    string t = num.substr(pos, i - pos);
                    long now = stol(t);
                    if(to_string(now).size() != t.size()) { continue; }
                    addOperatorHelper(res, num, target, cur + '+' + t, i, cv + now, now, '+');
                    addOperatorHelper(res, num, target, cur + '-' + t, i, cv - now, now, '-');
                    addOperatorHelper(res, num, target, cur + '*' + t, i, (op == '-')? cv + pv - pv * now : ((op == '+')? cv - pv + pv * now: pv * now), now, op);
                }
            }
        }
};

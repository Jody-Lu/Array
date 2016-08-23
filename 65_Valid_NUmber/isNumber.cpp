#include <iostream>

using namespace std;

class Solution {
    public:
        bool isNumber(string s) {
            int idx = 0;
            int count = 0;
            while(s[idx] == ' ') idx++;
            if(s[idx] == '+' || s[idx] == '-') idx++;
            while(idx < s.size()) {
                if(isdigit(s[idx])) {
                    count++;
                    continue;
                }
                else break;
            }
            if(count > 0) return true;
            return false;
        }
};

#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
    	NestedInteger deserialize(string s) {
            int idx = 0;
            char c = s[idx];
            if(c == '[')
                return parseList(s, idx);
            else
                return parseNumber(s, idx);
    	}

    private:
        NestedInteger parseList(string &s, int &idx) {
            idx++;
            NestedInteger root;
            while(idx < s.size()) {
                char c = s[idx];
                if(c == '[')
                    root.add(parseList(s, idx));
                else if(isNumber(c) || c == '-')
                    root.add(parseNumber(s, idx));
                else if(c == ',')
                    idx++;
                else if(c == ']')
                    break;
            }
            idx++;
            return root;
        }

        NestedInteger parseNumber(string &s, int &idx) {
            int n = 0;
            int positive = 1;
            if(s[idx] == '-') {
                positive = -1;
                idx++;
            }
            while(idx < s.size()) {
                char c = s[idx];
                if(isNumber(c)) {
                    n = 10 * n + (c - '0');
                    idx++;
                }
                else
                    break;
            }
            return NestedInteger(n * positive);
        }

        bool isNumber(char c) {
            return '0' <= c && c <= '9';
        }
};

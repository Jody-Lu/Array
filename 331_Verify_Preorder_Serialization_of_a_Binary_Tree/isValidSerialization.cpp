#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        bool isValidSerialization(string preorder) {
            int nodeCnt = 0, nullCnt = 0;
            vector<string> v = splitStr(preorder, ',');
            for(int i = 0; i < v.size(); i++) {
                if(v[i] == "#") ++nullCnt;
                else ++nodeCnt;
                // not to the end of v, but the tree is full.
                if(nullCnt >= nodeCnt + 1 && i != v.size() - 1)
                    return false;
            }
            return (nullCnt == nodeCnt + 1);
        }
        vector<string> splitStr(string s, char delimiter) {
            vector<string> res;
            string tmpstr;
            while(!s.empty()) {
                int idx = s.find_first_of(delimiter);
                if(idx == -1) {
                    res.push_back(s);
                    s.clear();
                }
                else {
                    res.push_back(s.substr(0, idx));
                    s = s.substr(idx + 1, s.size() - (idx + 1));
                }
            }
            return res;
        }
};

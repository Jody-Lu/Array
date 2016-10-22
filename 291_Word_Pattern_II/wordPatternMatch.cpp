#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        return dfs(pattern, str, 0, 0);
    }
    bool dfs(string& pattern, string& str, int pbegin, int sbegin) {
        if(pbegin == pattern.size() && sbegin == str.size()) {
            return true;
        }

        if(pbegin == pattern.size() && sbegin != str.size())
            return false;
        
        if(c2s.find(pattern[pbegin]) == c2s.end()) {
            for(int i = 1; i + sbegin <= str.size(); i++) {
                string tmpstr = str.substr(sbegin, i);
                if(s2c.find(tmpstr) != s2c.end())
                    continue;
                c2s[pattern[pbegin]] = str.substr(sbegin, i);
                s2c[tmpstr] = pattern[pbegin];
                if(dfs(pattern, str, pbegin + 1, sbegin + i))
                    return true;
                s2c.erase(tmpstr);
            }
            c2s.erase(pattern[pbegin]);
            return false;
        }
        else {
            string temp = c2s[pattern[pbegin]];
            if(temp == str.substr(sbegin, temp.size()))
                return dfs(pattern, str, pbegin + 1, sbegin + temp.size());
            else
                return false;
        }
    }
private:
    unordered_map<string, char> s2c;
    unordered_map<char, string> c2s;
};


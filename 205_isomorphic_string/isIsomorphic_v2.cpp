#include <vector>
#include <string>
#include <unordered_map>
// this problem can be solved using the same algorithm with 205.
class Solution {
	public:
    	bool isIsomorphic(string s, string t) {
            if(s.size() != t.size())
                return false;
            unordered_map<int, int> s2t;
            unordered_map<int, int> t2s;
            for(int i = 0; i < s.size(); i++)
            {
                if(s2t[s[i]] == 0 && t2s[t[i]] == 0)
                {
                    s2t[s[i]] = t[i];
                    t2s[t[i]] = s[i];
                    continue;
                }
                if(s2t[s[i]] != t[i])
                    return false;
            }
            return true;
    	}
};

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
	public:
    	bool isAnagram(string s, string t) {
            if(s.size() != t.size()) return false; 
            unordered<char, int> map;
            for(int i = 0; i < s.size(); ++i)
            {
                map[s[i]]++;
            }
            for(int i = 0; i < t.size(); ++i)
            {
                if(--map[t[i]] < 0)
                    return false;
            }
            return true;
    	}
};

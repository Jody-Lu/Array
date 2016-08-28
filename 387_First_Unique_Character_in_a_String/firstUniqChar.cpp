#include <iostream>
#include <unordered_map> 

using namespace std;

class Solution {
	public:
    	int firstUniqChar(string s) {
            unordered_map<char, int> counts;
            for(int i = 0; i < s.size(); i++)
                counts[s[i]]++;
            for(int i = 0; i < s.size(); i++)
                if(counts[s[i]] == 1)
                    return i;
            return -1;
    	}
};

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> counts;
        int odd = 0;
        
        for(int i = 0; i < s.size(); i++) {
            counts[s[i]]++;
        }
        
        for(auto p : counts) {
            if(p.second & 1) { odd++; }
        }

        return (s.size() % 2 == 0)? (odd == 0) : (odd == 1);
    }
};

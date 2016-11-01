class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> counts;
        int odd = 0, even = 0;
        
        for(int i = 0; i < s.size(); i++) {
            counts[s[i]]++;
        }
        
        for(auto it = counts.begin(); it != counts.end(); it++) {
            if((it->second) % 2 == 0) { even++; }
            else { odd++; }
        }
        return (s.size() % 2 == 0)? (odd == 0) : (odd == 1);
    }
};
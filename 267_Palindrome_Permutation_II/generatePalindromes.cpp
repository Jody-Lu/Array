#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> generatePalindromes(string s) {
            vector<string> palins;
            unordered_map<char, int> counts;
            int odd = 0;
            char mid;
            string half;

            for(char c : s) {
                counts[c]++;
            }

            for(auto p : counts) {
                if(p.second & 1) {
                    odd++;
                    mid = p.first;
                }
                if(odd > 1) { return palins; }
                half += string(p.second / 2, p.first);
            }

            palins = permutations(half);

            // p reference to string in palins
            for(string& p : palins) {
                string t(p);
                reverse(t.begin(), t.end());
                if(odd) {
                    t = mid + t;
                }
                p += t;
            }

            return palins;
        }
    
    private:
        vector<string> permutations(string& s) {
            vector<string> perms;
            string t(s);
            do {
                perms.push_back(t);
                next_permutation(t.begin(), t.end());
            } while(t != s);

            return perms;
        }
};

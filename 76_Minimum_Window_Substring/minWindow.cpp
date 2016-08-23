#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
	public:
    	string minWindow(string s, string t) {
            map<char, int> need;
            size_t i = 0, I = 0, J = 0;
            for(size_t k = 0; k < t.size(); k++)
                need[t[k]]++;

            size_t missing = t.size();
            for(size_t j = 0; j < s.size(); j++) {
                missing -= size_t(need[s[j]] > 0);
                need[s[j]]--;
                if(!missing) {
                    while(i < (j+1) && need[s[i]] < 0) {
                        need[s[i]]++;
                        i++;
                    }
                    if(!J || (j+1) - i <= J - I) {
                        I = i;
                        J = j + 1;
                    }
                }
            }
            return s.substr(I, J - I);
    	}
};

int main() {
    Solution sol;
    string s = "a";
    string t = "a";
    cout << sol.minWindow(s, t) << endl;
}

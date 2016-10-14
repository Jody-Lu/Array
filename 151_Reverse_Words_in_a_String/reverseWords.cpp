#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        void reverseWords(string& s) {
            reverse(s.begin(), s.end());
            int index = 0;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] != ' ') {
                    int j = i;
                    if(index != 0) s[index++] = ' ';
                    while(j < s.size() && s[j] != ' ')
                        s[index++] = s[j++];
                    reverse(s.begin() + index - (j - i), s.begin() + index);
                    i = j;
                }
            }
            s.erase(s.begin() + index, s.end());
        }
};

int main() {
    Solution sol;
    string s = "the sky is blue";
    sol.reverseWords(s);
    cout << s << endl;
}

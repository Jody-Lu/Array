#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            unordered_map<int, int> map;
            vector<string> res;
            int t = 0, i = 0, ss = s.size();
            while(i < 9)
            {
                t = t << 3 | (s[i++] & 7);
            }
            while(i < ss)
            {
                if(map[t = (t << 3 & 0x3FFFFFFF) | (s[i++] & 7)]++ == 1)
                    res.push_back(s.substr(i - 10, 10));
            }
            return res;
        }
};
int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution sol;
    vector<string> result;
    result = sol.findRepeatedDnaSequences(s);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}

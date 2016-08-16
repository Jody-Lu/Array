#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

class Solution
{
public:
	bool wordPattern(string pattern, string str)
	{
		istringstream strcin(str);
        string s;
        vector<string> vs;
        while(strcin >> s) vs.push_back(s);
        if(pattern.size() != vs.size()) return false;
        map<char, string> c2s;
        map<string, char> s2c;
        for(int i = 0; i < vs.size(); ++i)
        {
            /* memory this case, that's why we use two map
               to make sure that str and pattern are 1-to-1 mapping.
               "abba"
               "dog dog dog dog"
            */
            if(s2c[vs[i]] == 0 && c2s[pattern[i]] == "")
            {
                s2c[vs[i]] = pattern[i];
                c2s[pattern[i]] = vs[i];
                continue;
            }
            if(s2c[vs[i]] != pattern[i])
                return false;
        }
        return true;

	}
};


int main()
{
    string pattern = "abba";
    string str = "cat dog dog cat";
    Solution sol;
    cout << sol.wordPattern(pattern, str) << endl;

}

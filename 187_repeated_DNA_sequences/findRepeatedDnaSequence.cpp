#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
	public:
    	vector<string> findRepeatedDnaSequences(string s) {
            map<string, int> dict;
            vector<string> result;
            int i = 0;
            while(i + 10 < s.size())
            {
                dict[s.substr(i, 10)]++;
                i++;
            }

            for(map<string, int>::iterator it = dict.begin();
                it != dict.end();
                it++)
            {
                if(it -> second > 1)
                    result.push_back(it -> first);
            }

            return result;
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

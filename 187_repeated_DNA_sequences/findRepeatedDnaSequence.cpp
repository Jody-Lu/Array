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
            while(i + 10 <= s.size())
            {
                string sub = s.substr(i, 10);
                if(++dict[sub] > 1)
                {
                    result.push_back(sub);
                    dict[sub] = INT_MIN;
                }
                i++;
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

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > m;

        // O(n^2logn)
        for(string s : strs) {
            string t(s);
            // bottle next -- will take O(nlgn) time 
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }

        // O(n)
        for(auto it : m) {
            res.push_back(it.second);
        }

        return res;
    }

    // counting sort
    string strSort() {}
};
int main()
{
	int result = 0;
	string a = "";
	string b = "";
	vector<string > strs;
	strs.push_back(a);
	strs.push_back(b);
	Solution sol;
	cout << sol.groupAnagrams(strs).size() << endl;
	//char a = 'b';
	//cout << a << " " << int(a) - 96 << endl;

	for(int i = 0; i < a.size(); ++i)
	{
		result += int(a[i]);
	}
	//cout << result << endl;
	return 0;
}
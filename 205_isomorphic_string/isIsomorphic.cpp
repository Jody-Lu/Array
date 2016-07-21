#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
	bool isIsomorphic(string s, string t)
	{
		map<char, char> mapping_1;
		map<char, char> mapping_2;
		map<char, char>::iterator it_1;
		map<char, char>::iterator it_2;
		for(int i = 0, j = 0; i < s.size() && j < t.size(); ++i, ++j)
		{
			it_1 = mapping_1.find(s[i]);
			it_2 = mapping_2.find(t[j]);
			if(it_1 == mapping_1.end())
			{
				mapping_1[s[i]] = t[j];
			}
			else
			{
				if(it_1 -> second != t[j]) return false;
			}

			if(it_2 == mapping_2.end())
			{
				mapping_2[t[i]] = s[j];
			}
			else
			{
				if(it_2 -> second != s[j]) return false;
			}
		}
		return true;
	}

};

int main()
{
	Solution sol;
	cout << sol.isIsomorphic("ab", "aa") << endl;
	return 0;
}
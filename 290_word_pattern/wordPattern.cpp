#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	bool wordPattern(string pattern, string str)
	{
		vector<string> words;
		istringstream iss(str);
		map<char, string> mapping1;
		map<string, char> mapping2;

		copy(istream_iterator<string>(iss),
         	istream_iterator<string>(),
         	back_inserter(words));

		if(words.size() != pattern.size())
		{
			return false;
		}

		for(int i = 0; i < pattern.size(); ++i)
		{
			map<char, string>::iterator it1 = mapping1.find(pattern[i]);
			map<string, char>::iterator it2 = mapping2.find(words[i]);

			if(it1 != mapping1.end() || it2 != mapping2.end())
			{
				if(it1 != mapping1.end())
				{
					if(it1 -> second == words[i])
						continue;
					else
						return false;
				}
				else if(it2 != mapping2.end())
				{
					if(it2 -> second == pattern[i])
						continue;
					else
						return false;
				}
			}
			else
			{
				mapping1[pattern[i]] = words[i];
				mapping2[words[i]] = pattern[i];
			}

		}

		return true;

	}
};

int main()
{
	Solution sol;
	string pattern = "aaaa";
	string str = "dog dog dog dog";

	/*
	vector<string> words;
		istringstream iss(str);
		map<char, string> mapping;
		copy(istream_iterator<string>(iss),
         	istream_iterator<string>(),
         	back_inserter(words));
	*/
	cout << sol.wordPattern(pattern, str) << endl;
}

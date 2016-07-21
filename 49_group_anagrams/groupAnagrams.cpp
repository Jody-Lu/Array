#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
	/*
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		vector<vector<string> > result;
		map<int, vector<string> > mapping;
		map<int, vector<string> >::iterator it;
		int key = 0;
		for(int i = 0; i < strs.size(); ++i)
		{
			for(int charc = 0; charc < strs[i].size(); ++charc)
			{
				// hash function ascii * position + ascii
				key += int(strs[i][charc]) * (int(strs[i][charc]) - 96) + int(strs[i][charc]) * int(strs[i][charc]);
			}
			mapping[key].push_back(strs[i]);
			key = 0;
		}

		for(it = mapping.begin(); it != mapping.end(); ++it)
		{
			sort((it -> second).begin(), (it -> second).end());
			result.push_back(it -> second);
		}

		return result;
	}
	*/
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		vector<vector<string> > result;
		map<string, vector<string> > mapping;
		map<string, vector<string> >::iterator it;
		for(int i = 0; i < strs.size(); ++i)
		{
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			mapping[tmp].push_back(strs[i]);
		}

		for(it = mapping.begin(); it != mapping.end(); ++it)
		{
			sort((it -> second).begin(), (it -> second).end());
			result.push_back(it -> second);
		}

		return result;

	}
};


//["mod","mop","pip","tug","hop","dog","met","zoe","axe","mug","fdr","for","fro","fdr","pap","ray","lop","nth","old","eva","ell","mci","wee","ind","but","all","her","lew","ken","awl","law","rim","zit","did","yam","not","ref","lao","gab","sax","cup","new","job","new","del","gap","win","pot","lam","mgm","yup","hon","khz","sop","has","era","ark"]

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
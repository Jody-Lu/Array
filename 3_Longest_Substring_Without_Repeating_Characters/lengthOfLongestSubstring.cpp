#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	
		int front = 0;
		int first = front;
		int end = s.size() + 1;
		string result = "";

		if(s == "") return 0; // when length of s = 0, return 0

		s += s[s.size() - 1]; // To handle the cases: abcd or abccdefgh

		while(++first != end)
		{
			// substr(m, n): return substring from position m of length n
			if(s.substr(front, first - front).find(s[first]) != std::string::npos) // repeat
			{
				if((first - front) > result.size())
				{
					result = s.substr(front, first -front);
				}
				int tmp = first;
				// move front to the first non repeat: dvdf
				while(--tmp)
				{
					if(s[tmp] == s[first])
						break;
				}
				front = tmp + 1;
			}
		}

		return result.size();
	}

	// abcba
	int lengthOfLongestSubstring_v2(string s)
	{
		map<char, int> hash;

		for(int i = 0; i < s.size(); ++i)
		{
			hash[s[i]] = -1;
		}

		int start = 0, ans = 0;
		int i;
		for(i = 0; i < s.size(); ++i)
		{
			if(hash[s[i]] != -1) // repeat
			{
				cout << "yaa: " << i << " " << i - start << endl;
				if(ans < i - start) ans = i - start; // ans = 3

				for(int j = start; j < hash[s[i]]; ++j)
				{
					cout << "s[j] = " << s[j] << endl;
					hash[s[j]] = -1;
				}
				start = hash[s[i]] + 1;
				cout << "start: " << start << endl;
			}
			hash[s[i]] = i;
		}

		if(ans < i - start) ans = i - start;
		return ans;
	}

};

int main()
{
	string s = "abcba";
	// when i = 3, it repeats.
	// set hash[s[a]] = -1, since it may meet 'a' next i = 4..
	// move start to the next of duplicated term, and continue
	// O(n)
	Solution sol;
	//cout << s + "a" << endl;
	//cout << std::string::npos << endl;
	cout << sol.lengthOfLongestSubstring_v2(s) << endl;

	return 0;
}

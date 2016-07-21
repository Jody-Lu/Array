#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		bool result;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		result = (s == t);
		return result;
	}
};

int main()
{
	return 0;
}
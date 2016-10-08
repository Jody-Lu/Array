#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
	public:
    	bool isValid(string s)
        {
            stack<char> st;
            map<char, char> pmap = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                    st.push(s[i]);
                else
                {
                    if(st.empty() || pmap[st.top()] != s[i])
                        return false;
                    else st.pop();
                }
            }
            return (st.size() == 0);
    	}
};
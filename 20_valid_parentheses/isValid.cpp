class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        map<char, char> pmap = {{'{', '}'}, {'[', ']'}, {'(', ')'}};
        //pmap[')'] = '('; pmap[']'] = '['; pmap['}'] = '{';
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') 
                st.push(s[i]);
            else {
                if(st.empty() || st.top() != pmap[s[i]]) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
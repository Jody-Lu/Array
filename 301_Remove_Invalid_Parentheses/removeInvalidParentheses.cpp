class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        list<string> q, next; 
        q.push_front(s);
        
        while(!q.empty()) {
            while(!q.empty()) { 
                string curr = q.back();
                q.pop_back();
        
                if(isValid(curr)) {
                    res.push_back(curr);
                    return res;
                }
                
                for(int i = 0; i < curr.size(); i++) {
                    if(i > 0 && s[i] == s[i - 1]) { continue; }
                    char tmp = s[i];
                    curr.erase(curr.begin() + i);
                    next.push_front(curr);
                    curr.insert(curr.begin() + i, tmp);
                }
            }
            
            for(string pare : next) {
                if(isValid(pare)) {
                    res.push_back(pare);
                }
            }
            
            if(!res.empty()) { return res; }
            
            swap(q, next);
        }
        
        return res;
        
    }
private:
    
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(st.empty() || m[st.top()] != s[i]) {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        
        return st.empty();
    }
};
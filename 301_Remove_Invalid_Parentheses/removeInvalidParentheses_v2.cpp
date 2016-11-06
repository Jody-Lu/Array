class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        list<string> q;
        set<string> visited;
        bool found = false;

        q.push_front(s);
        visited.insert(s);

        while(!q.empty()) {
            string curr = q.back();
            q.pop_back();

            if(isValid(curr)) {
                res.push_back(curr);
                found = true;
            }

            if(found) { continue; }

            for(int i = 0; i < curr.size(); i++) {
                if(curr[i] != '(' && curr[i] != ')') { continue; }

                string t = curr.substr(0, i) + curr.substr(i + 1);

                if(visited.find(t) == visited.end()) {
                    q.push_front(t);
                    visited.insert(t);
                }

            }

        }
        return res;
    }
private:
    bool isValid(string s) {
        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '(') { count++; }
            if(c == ')' && count-- == 0) { return false; }
        }

        return (count == 0);
    }
};
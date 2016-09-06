#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool isdigit(char s) { return s >= '0' && s <= '9'; }


class Solution {
    public:
        string decodeString(string s) {
            stack<char> st;
            string res = "";
            for(int i = 0; i < s.size(); i++) {
                if(s[i] != ']') st.push(s[i]);
                else {
                    string tmpStr = "";
                    while(!st.empty() && st.top() != '[') {
                        tmpStr = st.top() + tmpStr;
                        st.pop();
                    }
                    // At this moment st.top() == '['
                    st.pop();
                    string times = "";
                    while(!st.empty() && isdigit(st.top())) {
                        times = st.top() + times;
                        st.pop();
                    }
                    int num = stoi(times);
                    for(int i = 0; i < num; i++)
                        res += tmpStr;
                    while(!st.empty() && isalpha(st.top())) {
                        res = st.top() + res;
                        st.pop();
                    }
                    cout << times << endl;
                }
            }
            cout << res << endl;
            return res;
        }
};

int main() {
    Solution sol;
    string s = "2[abc]3[cd]ef";
    sol.decodeString(s);
}

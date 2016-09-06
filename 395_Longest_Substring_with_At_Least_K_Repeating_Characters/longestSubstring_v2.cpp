#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
    public:
        int longestSubstring(string s, int k) {
            int N = s.size();
            /* If k > N, it's impossible to find a substring with k duplicates. */
            if(k > N) return 0;
            
            /* Count the number of characters in s. */
            map<char, int> counts;
            for(int i = 0; i < N; i++)
                counts[s[i]]++;
            
            int begin = 0, end = N - 1;
            /* Remove the character whose times is less than k from begin. */
            while(begin < N && counts[s[begin]] < k) begin++;
            /* Remove the character whose times is less than k from end. */
            while(end >= 0 && counts[s[end]] < k) end--;
            
            /* If s[begin : end + 1] contain character whose times is less than k,
               it must not be the answer. So we divide from the character we just find.
             */ 
            int i;
            for(i = begin; i <= end; i++) 
                if(counts[s[i]] < k)
                    return max(longestSubstring(s.substr(begin, i - begin + 1), k), \
                               longestSubstring(s.substr(i + 1, end - (i + 1) + 1), k));
            
            /* If the above for loop complete (i == (end + 1)), all characters' times are larger than k.
               So, return (end - begin + 1) else return 0
            */
            return (i == (end + 1))? (end - begin + 1) : 0;
        }
};

int main() {
    Solution sol;
    string s = "weitong";
    int k = 2;
    cout << sol.longestSubstring(s, k) << endl;
    s = "aaabb";
    k = 3;
    cout << sol.longestSubstring(s, k) << endl;
}

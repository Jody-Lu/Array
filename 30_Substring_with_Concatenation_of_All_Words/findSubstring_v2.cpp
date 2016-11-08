#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            unordered_map<string, int> counts;
            for(int i = 0; i < words.size(); i++)
                counts[words[i]]++;

            int n = s.size(), num = words.size(), len = words[0].size();
            vector<int> indexes;
            /**/
            for(int i = 0; i < n - num * len + 1; i++) {
                unordered_map<string, int> seen;
                int j = 0;
                for(; j < num; j++) {
                    string word = s.substr(i + j * len, len);
                    if(counts.find(word) != counts.end()) {
                        seen[word]++;
                        if(seen[word] > counts[word])
                            break;
                    }
                    else
                        break;
                }
                if(j == num) indexes.push_back(i);
            }
            return indexes;
        }
};

int main() {
    return 0;
}


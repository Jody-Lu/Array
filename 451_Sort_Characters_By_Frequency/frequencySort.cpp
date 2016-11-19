class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        priority_queue<pair<int, int> > pq;
        string res = "";

        for(char c : s) {
            counts[c]++;
        }

        for(auto it = counts.begin(); it != counts.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }

        while(!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            res += string(tmp.first, tmp.second);
        }

        return res;
    }
};
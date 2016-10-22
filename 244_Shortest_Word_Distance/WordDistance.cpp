class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++)
            mapping[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX;
        vector<int> v1 = mapping[word1];
        vector<int> v2 = mapping[word2];
        for(int i = 0; i < v1.size(); i++)
            for(int j = 0; j < v2.size(); j++)
                res = min(res, abs(v1[i] - v2[j]));
        return res;
    }
private:
    unordered_map<string, vector<int> > mapping;
};
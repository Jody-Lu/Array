#include <iostream>
#include <vector>
#include <utility>


using namespace std;

bool cmp(pair<int, int> i, pair<int, int> j) {
    if(i.first == j.first)
        return i.second > j.second;
    return i.first < j.first;
}

class Solution {
    public:
        int maxEnvelopes(vector<pair<int, int> >& envelopes) {
            int N = envelopes.size();
            if(N == 0) return 0;
            vector<pair<int, int> > LIS;
            sort(envelopes.begin(), envelopes.end(), cmp);
            LIS.push_back(envelopes[0]);
            for(int i = 1; i < N; i++) {
                if(envelopes[i].second > LIS.back().second)
                    LIS.push_back(envelopes[i]);
                else {
                    int begin = 0, end = LIS.size() - 1;
                    while(begin <= end) {
                        int mid = begin + (end - begin) / 2;
                        if(envelopes[i].second == LIS[mid].second) {
                            begin = mid;
                            break;
                        }
                        if(envelopes[i].second > LIS[mid].second)
                            begin = mid + 1;
                        else
                            end = mid - 1;
                    }
                    LIS[begin] = envelopes[i];
                }
            }
            return LIS.size();
        }
};

int main() {
    return 0;
}

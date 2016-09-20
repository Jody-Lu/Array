#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> readBinaryWatch(int num) {
            vector<string> res;
            for(int h = 0; h < 12; h++)
                for(int m = 0; m < 60; m++) {
                    if(bitset<10>((h << 6) + m).count() == num) // (h << 6) to prevent bits overlapping.
                        res.emplace_back(to_string(h) + (m < 10? ":0" : ":") + to_string(m));
                }
        }
};

int main() {
    return 0;
}

#include <iostream>
#include <vector>


using namespace std;

class Solution {
    public:
        vector<int> lexicalOrder(int n) {
            myn = n;
            for(int i = 1; i < 10; i++)
                dfs(i);
            return res;
        }
    private:
        void dfs(int i) {
            if(i <= myn) { 
                res.push_back(i);
                for(int d = 0; d < 10; d++) {
                    dfs(i*10 + d);
                }
            }
        }
        vector<int> res;
        int myn;
};

int main() {
    Solution sol;
    vector<int> res;
    res = sol.lexicalOrder(100);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

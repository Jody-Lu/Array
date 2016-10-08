#include <iostream>
#include <vector>


using namespace std;

class Solution {
    public:
        vector<int> lexicalOrder(int n) {
            vector<int> res;
            for(int i = 1; i < 10; i++)
                dfs(res, i, n);
            return res;
        }
    private:
        void dfs(vector<int> &res, int i, int &n) {
            if(i <= n)
            { 
                res.push_back(i);
                for(int d = 0; d < 10; d++)
                {
                    dfs(res, i*10 + d, n);
                }
            }
        }
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

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void sort(vector<int>& aList, int lo, int hi) {
            if(hi <= lo) return;
            int lt = lo, gt = hi;
            int v = aList[lo];
            int i = lo;
            while(i <= gt) {
                if(aList[i] < v) exch(aList, lt++, i++);
                else if(aList[i] > v) exch(aList, i, gt--);
                else i++;
            }

            sort(aList, lo, lt - 1);
            sort(aList, gt + 1, hi);
        }
    private:
        void exch(vector<int>& aList, int i, int j) {
            int tmp = aList[i];
            aList[i] = aList[j];
            aList[j] = tmp;
        }

};

int main() {
    int a[] = {4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1};
    vector<int> aList(a, a + 12);
    Solution sol;
    sol.sort(aList, 0, 11);
    for(int i = 0; i < aList.size(); i++)
        cout << aList[i] << " ";
    cout << endl;

}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int begin = 0, end = citations.size() - 1, mid;
            int len = citations.size();
            while(begin <= end) {
                mid = (begin + end) >> 1;
                if(citations[mid] == len - mid)
                    return len - mid;
                if(citations[mid] > len - mid)
                    end = mid - 1;
                else
                    begin = mid + 1;

            }
            return len - (end + 1);
        }

};

int main() {
    int arr[] = {1, 2, 3, 4};
    vector<int> c(arr, arr + 4);
    Solution sol;
    cout << sol.hIndex(c) << endl;

}

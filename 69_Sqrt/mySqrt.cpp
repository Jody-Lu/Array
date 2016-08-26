#include <iostream>

using namespace std;

class Solution {
	public:
    	int mySqrt(int x) {
            long begin = 1, end = x / 2 + 1;
            while(begin <= end) {
                long mid = begin + (end - begin) / 2;
                long sq = mid * mid;
                if(sq == x) return mid;
                if(sq > x) end = mid - 1;
                else begin = mid + 1;
            }
            return end;
    	}
};

int main() {
    int x = 2147395599;
    Solution sol;
    cout << sol.mySqrt(x) << endl;
}

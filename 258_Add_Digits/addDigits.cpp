#include <iostream>

using namespace std;

class Solution {
	public:
    	int addDigits(int num) {
            while(num >= 10) {
                int tmp = 0;
                while(num) {
                    tmp += num % 10;
                    num /= 10;
                }
                num = tmp;
            }
            return num;
    	}
};

int main() {
    Solution sol;
    int num = 38;
    cout << sol.addDigits(num) << endl;

}

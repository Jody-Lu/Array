#include <iostream>

using namespace std;

class Solution {
	public:
    	bool isPowerOfThree(int n) {
            if(!n) return false;
        	while(n % 3 == 0) {
        		n /= 3;
        		if(n & 1 == 0) return false;
        	}
        	return n == 1? true : false;
    	}
};
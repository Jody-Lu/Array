#include <iostream>
#include <vector>

using namespace std;

// Ff we meet data whose binary_len is larger than 8, then return false;
class Solution {
	public:
    	bool validUtf8(vector<int>& data) {
            int count = 0;
            for(auto c : data) {
                if(count == 0) {
                    if((c >> 5) == 0b110) count = 1;
                    else if((c >> 4) == 0b1110) count = 2;
                    else if((c >> 3) == 0b11110) count = 3;
                    else if((c >> 7)) return false;
                }
                else {
                    if((c >> 6) != 0b10) return false;
                    count--;
                }
            }
            return true;
    	}
};

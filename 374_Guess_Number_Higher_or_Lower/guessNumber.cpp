#include <iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int begin = 0, end = n;
        while(begin <= end) {
            int mid = begin + (end - begin) / 2;
            if(guess(mid) == 0) return mid;
            if(guess(mid) == 1) begin = mid + 1;
            else if(guess(mid) == -1) end = mid - 1;
        }
        return -1;
    }
};
#include <iostream>

using namespace std;

class Solution {
	public:
    	string getPermutation(int n, int k) {
            int i, j, fac = 1;
            string s = "";
            for(i = 1; i <= n; i++) {
                fac *= i;
                s.append(to_string(i));
            }

            for(i = 0, k--; i < n; i++) {
                fac /= (n - i);
                j = i + k / fac; // calculate index of char to put at s[i]
                char c = s[j];

                // remove c by shifting to cover up (adjust the right part).
                for(; j > i; j--)
                    s[j] = s[j - 1];

                k %= f;
                s[i] = c;

            }
            return s;
    	}
};

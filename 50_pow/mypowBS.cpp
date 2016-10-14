#include <iostream>

using namespace std;

class Solution {
	public:
    	double myPow(double x, int n)
        {
            if(n > 0)
                return mypow(x, n);
            else
                return 1.0 / mypow(x, -n);
    	}
    private:
        double mypow(double x, int n)
        {
            if(n == 0) return 1.0;
            double val = mypow(x, n/2);
            if(n % 2 == 0) return val * val;
            else return val * val * x;
        }
};

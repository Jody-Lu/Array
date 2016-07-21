#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution
{
public:
	int countPrimes(int n)
	{
		if(n == 0) return 0;
		int result = 0;
		vector<int> prime_table(n, -1); // -1:unmarked +1:marked
		prime_table[0] = 1; prime_table[1] = 1;
		for(int p = 2; p < sqrt(n); ++p)
		{
			if(prime_table[p] == 1) // marked
				continue;

			int num = p * p;
			while(num <= n)
			{
				prime_table[num] = 1;
				num += p;
			}
		}

		for(int i = 0; i < prime_table.size(); ++i)
		{
			//cout << prime_table[i] << " ";
			if(prime_table[i] == -1)
				result++;
		}

		return result;
	}
};

int main()
{
	Solution sol;
	cout << sol.countPrimes(6) << endl;
	//cout << sol.isPrime(9) << endl;
	return 0;
}

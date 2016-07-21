#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		add(digits, 1);
		return digits;
	}
private:
	void add(vector<int>& digits, int digit)
	{
		// 0 <= digit <= 9
		int c = digit; // carry digit

		for(vector<int>::iterator it = digits.end() - 1; it != digits.begin() - 1; --it)
		{
			*it += c;
			c = *it / 10;
			*it %= 10;
		}

		if(c > 0) digits.insert(digits.begin(), 1);
	}

};

int main()
{
	Solution sol;
	int arr[] = {1, 1, 1, 1, 1, 1, 1, 1};
	vector<int> digits(arr, arr + (sizeof(arr) / sizeof(*arr)));
	sol.plusOne(digits);

	for(vector<int>::iterator it = digits.begin(); it != digits.end(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl;

}

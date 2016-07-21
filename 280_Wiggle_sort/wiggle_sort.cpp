#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void wiggleSort(vector<int>& arr)
	{
		sort(arr.begin(), arr.end());
		for(int i = 2; i < arr.size(); i+=2)
		{
			sway(arr[i-1], arr[i]);
		}
	}

private:
	void sway(int& x, int& y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
};

int main()
{
	Solution sol;
	int ini[] = {1, 6, 2, 5, 3, 4};
	vector<int> arr(ini, ini+6);
	sol.wiggleSort(arr);

	for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << endl;
	}
}
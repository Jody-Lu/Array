#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
	vector<string> summaryRanges(vector<int>& nums)
	{

		vector<string> rng;
		int count = 0; //rng's counter

		if(nums.size() == 0)
		{
			return rng;
		}

		rng.push_back(in2str(nums[0]));

		for(int i = 0; i < nums.size()-1; ++i)
		{
			if(nums[i]+1 == nums[i+1])
			{
				if(rng[count].find("->") > rng[count].size())
				{
					rng[count] = (rng[count] + "->" + in2str(nums[i+1]));
				}
				else
				{
					rng[count] = rng[count].substr(0, rng[count].find(in2str(nums[i]))) + in2str(nums[i+1]);
				}

			}
			else
			{
				count++;
				rng.push_back(in2str(nums[i+1]));
			}
		}
		return rng;
	}
private:
	string in2str(int &i)
	{
		string s;
		stringstream ss(s);
		ss << i;

		return ss.str();
	}

};

// for test
int main()
{
	Solution sol;
	int ini[] = {0, 1};
	vector<int> arr(ini, ini+2);
	vector<string> result = sol.summaryRanges(arr);

	for(vector<string>::iterator it = result.begin(); it != result.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



#include <iostream>
#include <vector>
#include <map>

using namespace std;

/* version 2
class Solution {
public:
  int majorityElement(vector<int> &num) {
      int voter = num[0];
      int count = 1;

      int size = num.size();
      for(int i = 1; i< size; i++){
          if(count == 0){
              count++;
              voter = num[i];
          }
          else if(voter == num[i])
              count++;
          else
              count--;
      }
      return voter;
  }
};

*/


class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		map<int, int> result;
		for(vector<int>::iterator it = nums.begin();
			it != nums.end();
			++it)
		{
			result[*it] = 0;
		}

		for(vector<int>::iterator it = nums.begin();
			it != nums.end();
			++it)
		{
			++result[*it];
		}

		for(map<int, int>::iterator it = result.begin();
			it != result.end();
			++it)
		{
			cout << it -> first << "," << it -> second << endl;
			//if(it -> second > nums.size() / 2)
			//	return it -> first;
		}


		/*
		map<int, vector<int> > result;
		for(vector<int>::iterator it = nums.begin();
			it != nums.end();
			++it)
		{
			result[*it].push_back(*it);
		}

		for(map<int, vector<int> >::iterator it = result.begin();
			it != result.end();
			++it)
		{
			if((it -> second).size() > nums.size() / 2)
				return it -> first;
		}
		*/
	}
	/*
	int majorityElement(vector<int>& nums)
	{
		if(nums.size() == 1) return nums[0];
		sort(nums.begin(), nums.end());
		int count = 1;
		for(int i = 0; i < nums.size() - 1; ++i)
		{
			if(nums[i] == nums[i + 1])
			{
				count++;
				if(count > nums.size() / 2) return nums[i];
			}
			else
			{
				count = 1;
			}
		}
	}
	*/

};

int main()
{
	Solution sol;
	int result;
	int arr[] = {3, 2, 3};
	vector<int> nums(arr, arr + (sizeof(arr) / sizeof(*arr)));
	result = sol.majorityElement(nums);
	cout << result << endl;
}
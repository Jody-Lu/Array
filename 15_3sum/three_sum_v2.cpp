#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<vector<int> > threeSum(vector<int>& nums)
	{
		int count = 0;
		vector<vector<int> > result;
		if(nums.size() < 3){ return result; }

		sort(nums.begin(), nums.end());
		const int target = 0;

		//vector<int>::iterator j = nums.end() - 1;
		int j = nums.size() - 1;

		/*
		for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			while(*it == *(it+1) && (it+1) != nums.end()) it++;
			while(*j == *(j-1) && j > it) j--;

			int twosum = target - *(it);
			cout << *it << " " << *j << endl;
			vector<int> v(it, j);
			if(twoSum(v, twosum).size() != 0)
			{
				vector<int> r = twoSum(v, twosum);
				r.push_back(*it);
				result.push_back(r);
				it++;
				j--;
			}

		}
		*/

		for(int i = 0; i < nums.size();)
		{
			while(nums[j] == nums[j-1] && j > 0)
			{
				j--;
				//nums.pop_back();
			}
			while(nums[i] == nums[i+1] && i < nums.size()) i++;

			//cout << "Yaa: " << nums[i] << " " << nums[j] << endl;

			int twosum = target - nums[i];
			vector<int> v(nums.begin() + i - 1, nums.begin() + j + 1);
			if(twoSum(v, twosum).size() != 0)
			{
				vector<int> r = twoSum(nums, twosum);
				r.push_back(nums[i]);
				result.push_back(r);
				i++;
				j--;
				//nums.pop_back();
			}
			else
				break;

		}

		return result;
	}
private:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> mapping;
		vector<int> result;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size(); ++i)
		{
			mapping[nums[i]] = i; // nums' element : key
		}
		for(int i = 0; i < nums.size(); ++i)
		{
			const int gap = target - nums[i];
			if(mapping.find(gap) != mapping.end() && mapping[gap] > i)
			{
				result.push_back(nums[i]);
				result.push_back(nums[mapping[gap]]);
				break;
			}
		}
		return result;

	}
};


int main()
{
	Solution sol;
	int arr[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> nums(arr, arr+109);

	sort(nums.begin(), nums.end());
	for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *(it) << " ";
	}

	cout << endl << endl;

	vector<vector<int> > result = sol.threeSum(nums);
	for(vector<vector<int> >::iterator it = result.begin(); it != result.end(); it++)
	{
		for(vector<int>::iterator itt = it->begin(); itt != it->end(); itt++)
		{
			cout << *(itt) << " "; 
		}
		cout << endl;
	}

}






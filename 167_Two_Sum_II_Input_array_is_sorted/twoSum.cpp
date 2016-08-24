#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int begin = 0, end = numbers.size() - 1;
            vector<int> res;
            while(begin < end) {
                int sum = numbers[begin] + numbers[end];
                if(sum == target) {
                    res.push_back(end + 1);
                    res.push_back(begin + 1);
                    break;
                }
                if(sum > target) end--;
                else begin++;
            }
            return res;
        }
};

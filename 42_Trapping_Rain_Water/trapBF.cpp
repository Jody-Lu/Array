#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int trap(vector<int> &heights)
    {
        int res = 0;
        int n = heights.size();
        for(int i = 1; i < (n - 1); i++)
        {
            int left = i - 1, right = i + 1, lMax = heights[i], rMax = heights[i];
            /* Count the lMax correspond to heights[i]. */
            while(left >= 0)
            {
                if(heights[left] > lMax)
                    lMax = heights[left];
                left--;
            }
            /* Count the rMax correspond to heights[i]. */
            while(right < n)
            {
                if(heights[right] > rMax)
                    rMax = heights[right];
                right++;
            }
            /* Get the min between rMax & lMax. */
            int minH = min(lMax, rMax);
            res += (minH - heights[i]);
        }
        return res;
    }
};


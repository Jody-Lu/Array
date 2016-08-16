#include <iostream>
#include <vector>

class Solution {
	public:
    	int hIndex(vector<int>& citations) {
            sort(citations.begin(), citations.end());
            int length = citations.size();
            for(int i = 0; i < length; i++)
            {
                if(citations[i] >= length - i)
                    return length - i;
            }
            return 0;
    	}
};

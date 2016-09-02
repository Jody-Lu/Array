#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {} 
};

class Solution {
	public:
    	vector<Interval> insert(vector<Interval>& ins, Interval Inl) {
        	int idx = 0;
            while(Inl.start > ins[idx].start && In.end > ins[idx].end)
                idx++;
    	}
};

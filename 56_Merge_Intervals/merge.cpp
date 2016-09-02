#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {} 
};


struct less_first {
    bool operator ()(Interval const &a, Interval const &b) const {
        return a.start > b.start;
    }
};

class Solution {
	public:
    	vector<Interval> merge(vector<Interval>& intervals) {
            sort(intervals.begin(), intervals.end(), less_first());
            int idx = 0;
            while(idx < intervals.size() - 1) {
                if(intervals[idx].end < intervals[idx + 1].end &&
                   intervals[idx].end >= intervals[idx + 1].start) {
                    intervals[idx + 1].start = intervals[idx].start;
                    intervals.pop_back();
                }
                else if(intervals[idx].end >= intervals[idx + 1].end) {
                    intervals[idx + 1].start = intervals[idx].start;
                    intervals[idx + 1].end = intervals[idx].end;
                    intervals.pop_back();
                }
                else idx++;
            }
            return intervals;
    	}
};


int main() {
    Interval* a = new Interval(1, 2);
    cout << a -> start << " " << a -> end << endl;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& ins) {
        int n = ins.size();

        if(n == 0) { return true; }

        sort(ins.begin(), ins.end(), [](Interval a, Interval b) { return a.start < b.start; });

        for(int i = 0; i < (n - 1); i++) {
            if(ins[i].end > ins[i + 1].start) {
                return false;
            }
        }

        return true;
    }
};
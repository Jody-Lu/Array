class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        res = []
        intervals.sort(key=lambda x: x.start)
        idx = 0;

        while idx < len(intervals) - 1:
            # [1,4],[2,3] --> [1, 4]
            if intervals[idx + 1].end > intervals[idx].end >= intervals[idx + 1].start:
                intervals[idx + 1].start = intervals[idx].start
                del(intervals[idx])
            #[1,2],[2,3] --> [1, 3]
            elif intervals[idx].end >= intervals[idx + 1].end:
                intervals[idx + 1].start = intervals[idx].start
                intervals[idx + 1].end = intervals[idx].end
                del(intervals[idx])
            else:
                idx += 1
        return intervals
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        res = []
        begin = 0
        end = 0
        while begin < len(intervals) and newInterval.start > intervals[begin].end:
            begin += 1
        while end < len(intervals) newInterval.end > intervals[end].end:
            end += 1

        res += intervals[:begin]
        right = newInterval.end if newInterval.end < intervals[end].start else intervals[end].end
        res.append(Interval(min(newInterval.start, intervals[begin].start), right))
        res += intervals[end+ 1:]
        return res

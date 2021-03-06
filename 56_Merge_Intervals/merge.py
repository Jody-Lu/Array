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






intervals = [Interval(4, 3), Interval(1, 2)]
sol = Solution()
sol.merge(intervals)

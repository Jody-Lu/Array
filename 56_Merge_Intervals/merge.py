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
            if intervals[idx].end >= intervals[idx + 1].start:
                intervals[idx + 1].start = intervals[idx].start
                del(intervals[idx])
            else:
                idx += 1






intervals = [Interval(4, 3), Interval(1, 2)]
sol = Solution()
sol.merge(intervals)

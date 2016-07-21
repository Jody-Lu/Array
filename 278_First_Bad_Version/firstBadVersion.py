class Solution(object):
    def firstBadVersion(self, n):
        begin, end = 1, n

        while begin <= end:
            mid = (begin + end) / 2
            if mid > 1 and isBadVersion(mid) and not isBadVersion(mid - 1):
                return mid
            if isBadVersion(mid):
                end = mid - 1
            else:
                begin = mid + 1
        return begin
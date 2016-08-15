class Solution(object):
    def maxArea(self, height):
        begin = 0
        end = len(height) - 1
        res = -1
        while begin < end:
            area = min(height[begin], height[end]) * (end - begin)
            res = max(res, area)
            if height[begin] <= height[end]:
                begin += 1
            else:
                end -= 1
        return res


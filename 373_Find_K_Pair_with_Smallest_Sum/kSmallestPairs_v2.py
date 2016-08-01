from heapq import heappop, heappush, heapreplace
class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        if len(nums1) * len(nums2) <= k:
            return [[i, j] for i in nums1 for j in nums2]

        h = [[n + nums2[0], n, 0] for n in nums1]
        res = []

        for i in xrange(k):
            psum, n, index = h[0]
            res.append([n, psum - n])
            if index + 1 == len(nums2):
                heappop(h)
            else:
                heapreplace(h, [n + nums[index + 1], n, index + 1])

        return res


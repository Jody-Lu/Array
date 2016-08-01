from heapq import heapify, heappop
class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        if not nums1 or not nums2: return []
        if k > len(nums1) * len(nums2):
            k = len(nums1) * len(nums2)
        h = []
        res = []
        for i in xrange(len(nums1)):
            for j in xrange(len(nums2)):
                h.append((nums1[i], nums2[j]))
                #h.append((nums1[i] + nums2[j], (nums1[i], nums2[j])))
        heapify(h)
        return [list(heappop(h)) for _ in xrange(k)] 
        #return [list(heappop(h)[1]) for _ in xrange(k)]

sol = Solution()
nums1 = [1, 1, 2]
nums2 = [1, 2, 3]
k = 2
#nums1 = [-476570184,-423568801,-385585840,-375390924,-364630569,-359795128,-281872968,-126410430,-75677925,-54214495,-49178055,-32637211,-32198215,3413177,19045759,62248526,67551536,113606647,155411580,164755463,164781059,203133270,277305105,284913246,285973110,296436629,325431544,357294459,378678394,399786157]
#nums2 = [-408663357,-404578641,-376531700,-311642519,-294905976,-232001207,-183530032,-141524508,-115652480,-70696522,-63386299,-54656543,-32316999,29714175,33993996,45020708,62165363,84210823,93905151,102177224,209285622,288668099,328300713,338684779,342861859,384940859,408019604,410097843,458721542,475395296]
#k = 1000
print sol.kSmallestPairs(nums1, nums2, k)



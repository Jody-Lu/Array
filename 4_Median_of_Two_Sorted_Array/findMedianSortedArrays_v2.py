class Solution(object):
    def select(self, nums, j):
        if len(nums) < 10:
            nums.sort()
            return float(nums[j]) if len(nums) % 2 == 1 else (nums[j - 1] + nums[j]) / 2.0
        S = []
        lIndex = 0
        while lIndex + 5 < len(nums) - 1:
            S.append(nums[lIndex: lIndex + 5])
            lIndex += 5

        S.append(nums[lIndex:])
        Meds = []

        for subList in S:
            Meds.append(self.select(subList, int((len(subList) - 1) / 2)))
        med = self.select(Meds, int((len(Meds)-1)/2))
        L1 = []
        L2 = []
        L3 = []
        for i in L:
            if i < med:
                L1.append(i)
            elif i > med:
                L3.append(i)
            else:
                L2.append(i)
        if j < len(L1):
            return self.select(L1, j)
        elif j < len(L2) + len(L1):
            return L2[0]
        else:
            return select(L3, j-len(L1)-len(L2))

    def findMedianSortedArrays(self, nums1, nums2):
        j = (len(nums1) + len(nums2)) / 2
        return self.select(nums1 + nums2, j)

nums1 = [1, 2]
nums2 = [3, 4]
sol = Solution()
print sol.findMedianSortedArrays(nums1, nums2)


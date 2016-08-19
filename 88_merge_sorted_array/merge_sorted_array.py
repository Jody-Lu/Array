class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i_1, i_2, icur = m - 1, n - 1, m + n - 1;
        while i_1 >= 0 and i_2 >= 0:
            if nums1[i_1] >= nums2[i_2]:
                nums1[icur] = nums1[i_1]
                i_1 -= 1
            else:
                nums1[icur] = nums1[i_2]
                i_2 -= 1
            icur -= 1

        while i_2 >= 0:
            nums1[icur] = nums2[i_2]
            icur -= 1
            i_2 -= 1


class Solution(object):
    def median(self, nums):
        mid = (len(nums) - 1) / 2
        if len(nums) % 2 == 0:
            return (nums[mid] + nums[mid + 1]) / 2.0
        else:
            return float(nums[mid])
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        begin1 = 0
        begin2 = 0
        end1 = len(nums1) - 1
        end2 = len(nums2) - 1
        middle = (len(nums1) + len(nums2)) / 2

        while begin1 < end1 and begin2 < end2:
            mid1 = (begin1 + end1) / 2
            mid2 = (begin2 + end2) / 2
            # nums2[mid2 + 1 :] are bigger than nums1[0: mid1 + 1]
            if nums1[mid1] <= nums2[mid2]:
                end2 = mid2
                begin1 = mid1
            # nums1[mid1 + 1 :] are bigger than nums2[0:mid2 + 1]
            elif nums1[mid1] > nums2[mid2]:
                end1 = mid1
                begin2 = mid2
        
        print begin1, end1
        print begin2, end2
        print "--------------------------"
        ######################################
        if begin1 == end1:
            #if nums1[begin1] < nums2[0] or nums1[begin1] > nums2[-1]:
            #    return self.median(nums2)
            
            while begin2 < end2:
                mid2 = (begin2 + end2) / 2
                if nums2[mid2] >= nums1[begin1]:
                    end2 = mid2 - 1
                else:
                    begin2 = mid2 + 1
        elif begin2 == end2:
            #if nums2[begin2] < nums1[0] or nums2[begin2] > nums1[-1]:
            #    return self.median(nums1)
            while begin1 < end1:
                mid1 = (begin1 + end1) / 2
                if nums1[mid1] >= nums2[begin2]:
                    end1 = mid1 - 1
                else:
                    begin1 = mid1 + 1

        print begin1, end1
        print begin2, end2
        #print mid1, mid2 
        return (float(nums1[begin1]) + float(nums2[begin2])) / 2


sol = Solution()
nums1 = [1, 2, 6]
nums2 = [3, 4, 5]
#print sol.median(nums1)
#print sol.median(nums2)

sol.findMedianSortedArrays(nums1, nums2)
                


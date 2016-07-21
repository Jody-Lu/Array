class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = 0
        r = len(nums) - 1
        
        # find rotate point
        while l < r:
            mid = (l + r) / 2
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid
        ro = l
        l = 0
        r = len(nums) - 1

        while l <= r:
            mid = (l + r) / 2
            realmid = (mid + ro) % len(nums)
            if nums[realmid] == target: return realmid
            if target > nums[realmid]: l = mid + 1
            else:
                r = mid - 1
        
        return -1         
        

       #
         
        """
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) / 2
            if nums[mid] == target: return mid

            if nums[mid] < nums[r]:
                if target > nums[mid] and target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            else:
                if target >= nums[l] and target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1

        return -1
        """
        """
        start = 0
        end = len(nums) - 1
        pivot = 1
        if nums[0] > nums[-1]:
            while nums[pivot] > nums[pivot-1]:
                pivot += 1

            if target >= nums[0]:
                start = 0
                end = pivot - 1
            else:
                start = pivot
                end = len(nums) - 1
        else:
            start = 0
            end = len(nums) - 1

        while start <= end:
            pin = (start + end) / 2
            if target == nums[pin]:
                return pin
            
            if target > nums[pin]:
                start = pin + 1
            else:
                end = pin - 1

        return -1
        """
        #return -1 if nums[pin] != target else pin

if __name__ == '__main__':
    sol = Solution()
    nums = [4, 5, 6, 7, 0, 1, 2]
    #nums = [1, 2, 3, 4, 5]
    target = 8
    print sol.search(nums, target)



    

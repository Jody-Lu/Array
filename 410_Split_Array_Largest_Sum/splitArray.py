class Solution(object):
    def splitArray(self, nums, m):
        begin = max(nums)
        end = sum(nums)

        while(begin <= end):
            mid = (begin + end) / 2
            if not self.isValid(nums, m, mid):
                begin = mid + 1
            else:
                end = mid - 1
        return begin


    def isValid(self, nums, m, target):
        num = 0
        count = 0
        for i in xrange(len(nums)):
            num += nums[i];
            if(num > target):
                num = nums[i]
                count += 1
                if(count >= m):
                    return False;
        return True

if __name__ == '__main__':
    sol = Solution()
    nums = [7, 2, 5, 10, 8]
    m = 2
    print sol.splitArray(nums, m)


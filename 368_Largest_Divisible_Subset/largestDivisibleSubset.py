import time
class Solution(object):
    def largestDivisibleSubset(self, nums):
        if not nums: return []
        nums = sorted(nums)
        f = [[nums[0]]]
        
        for i in xrange(1, len(nums)):
            f.append([nums[i]])
            for j in xrange(len(f)):
                if not nums[i] % f[j][-1] and len(f[j]) + 1 > len(f[i]):
                    f[i] = f[j] + [nums[i]]
        
        return max(f, key=len)

sol = Solution()
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99]
#print nums
start = time.time()
sol.largestDivisibleSubset(nums)
print time.time() - start



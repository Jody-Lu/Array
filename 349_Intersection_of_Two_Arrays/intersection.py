class Solution(object):
    def intersection(self, nums1, nums2):
        return list(set(num1) & set(num2))

sol = Solution()
num1 = [1, 2, 2, 1]
num2 = [2, 2]
print sol.intersection(num1, num2)

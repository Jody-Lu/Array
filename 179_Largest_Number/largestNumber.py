class Solution(object):
    def numToDigit(self, num):
        res = []
        while num:
            res.append(num % 10)
            num /= 10
        return res[::-1]

    def compare(self, num1, num2):
        num1 = self.numToDigit(num1)
        num2 = self.numToDigit(num2)
        for i in xrange(min(len(num1), len(num2))):
            if num1[i] > num2[i]:
                return True
            elif num2[i] > num1[i]:
                return False

        return len(num1) > len(num2)


    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: string
        Note: [121,12]
        """
        nums.sort(cmp=self.compare)
        nums.reverse()
        return ''.join([str(num) for num in nums]).lstrip('0') or '0'

sol = Solution()
num1 = 123456
num2 = 123
nums = [3, 30, 34, 5, 9]
print sol.largestNumber(nums)



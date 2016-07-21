class Solution(object):
    def isPerfectSquare(self, num):
        #if not num: return False
        begin = 1
        end = num / 2 + 1

        while begin < end:
            mid = (begin + end) / 2
            square = mid * mid
            if square == num: 
                return True
            if num > square:
                begin = mid + 1
            else:
                end = mid - 1

        return begin * begin == num

sol = Solution()
num = 0
print sol.isPerfectSquare(num)



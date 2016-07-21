class Solution(object):
    def isPalindrome(self, s):
        left = 0
        right = len(s) - 1
        s = s.lower()

        while left < right:
            while not s[left].isalnum() and left < right: left += 1
            while not s[right].isalnum() and left < right: right -= 1

            print s[left], s[right]
            if s[left] != s[right]: return False
            else:
                left += 1
                right -= 1
        else:
            return True

if __name__ == '__main__':
    sol = Solution()
    #s = "      A m a#########n, a/////// p   l an, a ca  na  l: Pa   n     a  ma   "
    s = ".....,,,"
    print sol.isPalindrome(s)

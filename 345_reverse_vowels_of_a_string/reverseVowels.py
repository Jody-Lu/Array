class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = {'a', 'e', 'i', 'o', 'u'}
        s = list(s)
        begin = 0
        end = len(s) - 1

        while begin < end:
            while begin < end and s[begin].lower() not in vowels:
                begin += 1
            while begin < end and s[end].lower() not in vowels:
                end -= 1
            s[begin], s[end] = s[end], s[begin]
            begin += 1
            end -= 1

        return ''.join(s)


if __name__ == '__main__':
    sol = Solution()
    s = 'aA'
    print sol.reverseVowels(s)
            

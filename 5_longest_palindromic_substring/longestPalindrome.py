class Solution(object):
    def longestPalindrome(self, s):
        def match(left, right, text):
            i = 0
            while left - i >= 0 and right + i < len(text) and text[left - i] == text[right + i]:
                i += 1
            return i
        
        even = False

        if len(s) % 2 == 0:
            even = True
            s = s[0: len(s)/2] + '.' + s[len(s)/2:len(s)]

        z = [0] * len(s)
        z[0] = 1
        left = 0
        right = 0

        for i in range(1, len(s)):
            i_mapping = left - (i - left)
            n = right + 1 - i

            if i > right:
                z[i] = match(i, i, s)
                left = i
                right = i + z[i] - 1
            elif z[i_mapping] == n:
                z[i] = n + match(i - n, i + n, s)
                left = i
                right = i + z[i] - 1
            else:
                z[i] = min(z[i_mapping], n)

        max_length = max(z)
        index = z.index(max_length)
        result = s[(index - max_length + 1):(index + max_length)]

        return result.replace('.', '') if even else result

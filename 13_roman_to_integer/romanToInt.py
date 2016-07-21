class Solution(object):
    def romanToInt(self, s):
        result = 0
        ROMANS = {'I': 1,
                'V': 5,
                'X': 10,
                'L': 50,
                'C': 100,
                'D': 500,
                'M': 1000}
        
        for idx in xrange(1, len(s)):
            #print result, s[idx]
            #result += ROMANS[s[idx]]
            if ROMANS[s[idx]] > ROMANS[s[idx - 1]]:
                result -= ROMANS[s[idx - 1]]
            else:
                result += ROMANS[s[idx - 1]]

        return result + ROMANS[s[-1]]

if __name__ == '__main__':
    sol = Solution()
    print sol.romanToInt('MMMCCXXXV')
            


class Solution(object):
    def intToRoman(self, num):
        result = ''
        ROMANS = (('M', 1000),
                ('CM', 900),
                ('D', 500),
                ('CD', 400),
                ('C', 100),
                ('XC', 90),
                ('L', 50),
                ('XL', 40),
                ('X', 10),
                ('IX', 9),
                ('V', 5),
                ('IV', 4),
                ('I', 1))

        for item in ROMANS:
            while num >= item[1]:
                num -= item[1]
                result += item[0]
            if num == 0:
                break

        return result

if __name__ == '__main__':
    num = 3235
    sol = Solution()
    print sol.intToRoman(num)

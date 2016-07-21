class Solution(object):
    def convert(self, s, numRows):
        if numRows == 1: return s
        result = [''] * numRows
        interval = 2 * numRows - 2
        s_len = len(s)

        for j in range(0, s_len, interval):
            result[0] += s[j]

        for i in range(1, numRows -1):
            inter = i << 1
            j = i
            while j < s_len:
                result[i] += s[j]
                inter = interval - inter
                j += inter

        for j in range(numRows - 1, s_len, interval):
            result[numRows - 1] += s[j]
        print result
        return ''.join(result)

    # Version 2
    """
    class Solution(object):
    def convert(self, s, nRows):
        if nRows==1: return s
        period= 2*(nRows -1)
        lines = [""] * nRows
        d={} # dict remainder:line
        for i in xrange(period):
            if i < nRows: d[i] = i
            else: d[i] = period - i

        for i in xrange(len(s)):
            lines[ d[i%period] ] += s[i]
        
        return "".join(lines)
    """


if __name__ == '__main__':
    sol = Solution()
    result = sol.convert('ABCD', 4)
    print result


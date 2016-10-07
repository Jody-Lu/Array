class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if not num: return '0'
        num = num if num >= 0 else (0xffffffff + num + 1)
        num_dic = {10 : 'a', 11:'b', 12:'c', 13:'d', 14:'e', 15:'f'}
        for i in xrange(10):
        	num_dic[i] = str(i)

        digits = []
        base = 16

        while(num):
        	digits.insert(0, num_dic[num % base])
        	num /= 16

        return "".join(digits)

sol = Solution()
print sol.toHex(0)

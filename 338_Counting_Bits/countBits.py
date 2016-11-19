class Solution(object):
    def countBits(self, num):
        """
        : type num: int
        : rtype: List[int]
        """
        """
        res = [0] * (num + 1)
        for i in xrange(num + 1):
            res[i] = bin(i).count('1')
        
        return res
        """
        #return [bin(i).count('1') for i in xrange(num + 1)]
        for i in xrange(num + 1):
            print i, bin(i)

    def countBits_v2(self, num):
        """
        DP: 
        1. If i is even, i must have the same #bit with i >> 1 (Since the last bit of i must be 0)
        2. If i is odd, its last bit must equal to 1 
        and #bits equal to #bit of i >> 1 + 1
        Ex: 5 --> 0, 1, 2, 3, 4, 5
        res[0] = 0
        res[1] = res[1 >> 1] + 1 & 1 = 1
        res[2] = res[2 >> 1] + 2 & 1 = res[1] = 1
        res[3] = res[3 >> 2] + 3 & 1 = res[1] + 1 = 2
        res[4] = res[4 >> 2] + 4 & 1 = res[2] + 0 = 2
        res[5] = res[5 >> 2] + 5 & 1 = res[2] + 1 = 3
        """
        res = [0] * (num + 1)
        for i in xrange(num + 1):
            res[i] = res[i >> 1] + (i & 0x1)
        print res

sol = Solution()
num = 4
print sol.countBits_v2(num)


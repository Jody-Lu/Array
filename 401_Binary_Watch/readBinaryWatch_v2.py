class Solution(object):
    def readBinaryWatch(self, num):
        return ["%d:%02d" % (h, m) 
                for h in xrange(12) for m in xrange(60)
                if(bin(h) + bin(m)).count('1') == num]

sol = Solution()
print sol.readBinaryWatch(1)

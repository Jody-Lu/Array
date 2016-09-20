class Solution(object):
    def findNthDigit(self, n):
        if n < 10: return n
        pow = 0
        tmp = n
        while tmp > 0:
            tmp -= (9 * (10 ** pow)) * (pow + 1)
            pow += 1
        
        Nth = tmp + (9 * (10 ** (pow - 1))) * pow
        #print "Nth, pow: ", Nth, pow
        # pow digits, the Nth digit
        v = Nth / pow
        count = v if Nth % pow == 0 else v + 1
        digit = Nth % pow if Nth % pow != 0 else pow
        
        #print "count, digit: ", count, digit
        N = (10 ** (pow - 1) + count - 1)
        n = pow - digit
        #print N
        while n > 0:
            N /= 10
            n -= 1
        return N % 10 

sol = Solution()
print sol.findNthDigit(15)



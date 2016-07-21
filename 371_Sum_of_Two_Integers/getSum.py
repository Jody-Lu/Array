class Solution(object):
    def getSum(self, a, b):
        bits_a = list(bin(a)[2:][::-1])
        bits_b = list(bin(b)[2:][::-1])
        length = max(len(bits_a), len(bits_b)) + 1
        while len(bits_a) < length:
            bits_a.append('0')
        while len(bits_b) < length:
            bits_b.append('0')
        print bits_a
        print bits_b
        
        res = []
        carry = 0
        for i in xrange(length):
            bita = int(bits_a[i])
            bitb = int(bits_b[i])
            bit = bita ^ bitb ^ carry
            carry = 1 if bita & bitb or bita & carry or bitb & carry else 0
            res.insert(0, str(bit))
        return int(''.join(res), 2)
        
sol = Solution()
a = -1
b = 2
print bin(a)
print bin(b)
print sol.getSum(a, b)




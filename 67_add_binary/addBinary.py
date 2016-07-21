class Solution(object):
    def addBinary(self, a, b):
        if len(a) == 0: return b
        if len(b) == 0: return a


    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """

        while len(a) < len(b):
            a = '0' + a
        
        while len(b) < len(a):
            b = '0' + b
        a = a[::-1]
        b = b[::-1]
        
        carry = 0
        arr = [0] * len(a)

        for i in xrange(len(a)):
            val = int(a[i]) +int(b[i]) + carry
            if val > 1:
                arr[i] = str(val % 2)
                carry = val / 2
            else: 
                arr[i] = str(val)
                carry = 0
        
        if carry > 0: arr.append(str(carry))
        return ''.join(arr[::-1]) 

sol = Solution()
a = '1001'
b = '1111'
print sol.addBinary(a, b)



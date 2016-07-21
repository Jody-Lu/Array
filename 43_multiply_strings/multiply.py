class Solution(object):
    """
    def add(self, num1, num2):
        while len(num1) < len(num2):
            num1.insert(0, '0')
        while len(num2) < len(num1):
            num2.insert(0, '0')
        
        result = []
        i = 1
        j = 1
        carry = 0
        while i <= len(num1) and j <= len(num2):
            val = int(num1[-i]) + int(num2[-j]) + carry 
            if val < 10:
                result.insert(0, str(val))
                carry = 0
            else:
                result.insert(0, str(val%10))
                carry = val / 10
            i += 1
            j += 1
        if carry > 0: result.insert(0, str(carry))
        return result
    def multiply(self, num1, num2):
        if len(num2) > len(num1):
            num1, num2 = num2, num1
        res = []
        result = []
        i = 1
        j = 1
        carry = 0
        carry_add = 0
        for i in xrange(1, len(num2) + 1):
            for j in xrange(1, len(num1) + 1):
                val = int(num1[-j]) * int(num2[-i]) + carry
                if val < 10:
                    result.insert(0, str(val))
                    carry = 0
                else:
                    result.insert(0, str(val%10))
                    carry = val / 10
            
            result += ['0'] * (i - 1) 
            res = self.add(result, res)
            result = []

        return ''.join(res)
    """
    def multiply(self, num1, num2):
        num1 = num1[::-1]
        num2 = num2[::-1]
        len1 = len(num1)
        len2 = len(num2)
        arr = [0] * (len1 + len2)

        for i in xrange(len1):
            for j in xrange(len2):
                arr[i + j] += int(num1[i]) * int(num2[j])
        ans = []
        for i in xrange(len(arr)):
            digit = arr[i] % 10
            carry = arr[i] / 10
            if i < len(arr) - 1:
                arr[i+1] += carry
            ans.insert(0, str(digit))
        while ans[0] == 0 and len(ans) > 1:
            del ans[0]

        return ''.join(ans)



sol = Solution()
num2 = "256117489511377083148593685533950561400363410418754703282767252221661609163404299"
num1 = "61200496111643709081218550902198211480012378840070191147459688611759881218205422431757614"
print sol.multiply(num1, num2)


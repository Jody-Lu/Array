class Solution(object):
    def numDecodings(self, s):
        if not s or s[0] == '0': return 0
        f = [None] * (len(s) + 1)
        f[0] = f[1] = 1
        for idx in range(1, len(s)):
            if s[idx] == '0':
                if int(s[idx-1:idx+1]) > 26 or s[idx-1] == '0': return 0
                else: 
                    f[idx+1] = f[idx-1]
            else:
                if s[idx-1] == '0':
                    f[idx+1] = f[idx]
                    continue
                if int(s[idx-1:idx+1]) <= 26:
                    f[idx+1] = f[idx] + f[idx-1]
                else: 
                    f[idx+1] = f[idx]

        return f[-1]

sol = Solution()
s = '1111'
#s = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948"
print sol.numDecodings(s)


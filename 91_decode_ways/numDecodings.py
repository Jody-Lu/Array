class Solution(object):
    res = 0
    test = 0
    def numDecodings(self, s):
        if not s: return 0
        
        def dfs(start):
            if start >= len(s): 
                self.test += 1
                return 
            
            cnt = 1
            while cnt <= 2:
                if start + cnt > len(s): return
                if s[start:start+cnt][0] == '0': return
                if cnt == 2 and int(s[start:start+cnt][0]) >= 3: return
                if int(s[start:start+cnt]) > 26: return 
                else:
                    dfs(start + cnt)
                cnt += 1      
        dfs(0)

        return self.test
        
sol = Solution()
s = '1111'
#s = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948"
print sol.numDecodings(s)

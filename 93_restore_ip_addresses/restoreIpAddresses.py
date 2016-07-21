class Solution(object):
    def isValid(self, num):
        if len(str(int(num))) < len(num) or int(num) > 255: return False
        else: return True

    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        def dfs(stack, start):
            if len(stack) == 4:
                if start >= len(s) and stack not in result:
                    result.append(stack)
                return

            cnt = 1
            while cnt <= 3:
                if start + cnt > len(s): return 
                if self.isValid(s[start:start + cnt]):
                    dfs(stack + [s[start:start + cnt]], start + cnt)
                else: return
                cnt += 1

        dfs([], 0)
        result = ['.'.join(item) for item in result]
        return result

sol = Solution()
s = '25525511135'
#print sol.isValid(s)
print sol.restoreIpAddresses(s)




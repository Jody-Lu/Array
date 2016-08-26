class Solution(object):
    def wordBreak(self, s, wordDict):
        if not wordDict: return False
        dp = [False] * (len(s) + 1)
        dp[0] = True
        wordDict.sort()

        for i in xrange(len(s)):
            for word in wordDict:
                if(i + len(word) > len(s)): break
                if(i + len(word) <= len(s) and word == s[i:i + len(word)] and not dp[i + len(word)]):
                    dp[i + len(word)] = True & dp[i]

        return dp[len(s)]

sol = Solution()
s = "aaaaaaa"
wordDict = ["aaaa","aaa"]
print sol.wordBreak(s, wordDict)

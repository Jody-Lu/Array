class Solution(object):
    def wordBreak(self, s, wordDict):
        sentences = []
        
        def dfs(s, sentence, wordDict):
            if len(s) == 0:
                sentences.append(sentence)

            for idx in xrange(len(s)):
                for j, w in enumerate(wordDict):
                    if w == s[idx:idx + len(w)]:
                        dfs(s[idx + len(w):], sentence + w + " ", wordDict[j+1:])

        dfs(s, "", wordDict)
        print sentences

sol = Solution()
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
sol.wordBreak(s, wordDict)



class Solution(object):
    def findLadders(self, beginWord, endWord, wordlist):
        result = [beginWord]
        res = []
        for r in result:
            s_top = result.pop()
            for w in wordlist:
                if self.is_str_diff_one(s_top, w):
                    res.append(w)
            
        print res
        """
        def bfs(stack, words):
            res = []
            while stack:
                s_top = stack.pop()
                if self.is_str_diff_one(s_top, endWord):
                    return 
                tmp = []
                for w in words:
                    if self.is_str_diff_one(s_top, w):
                        tmp.append(w)
                print tmp
                stack = tmp

        bfs([beginWord], wordlist)
        """

    def is_str_diff_one(self, s1, s2):
        cnt = 0
        for i in xrange(len(s1)):
            if cnt >= 2: return False
            if s1[i] != s2[i]: cnt += 1

        return False if cnt >= 2 or cnt == 0 else True

sol = Solution()
beginWord = "hit"
endWord = "cog"
wordlist = ["hot","dot","dog","lot","log"]
#beginWord = "qa"
#endWord = "sq"
#wordlist = ["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]
sol.findLadders(beginWord, endWord, wordlist)

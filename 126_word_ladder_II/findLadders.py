class Solution(object):

    # use BFS: we can find the minimum 
    def findLadders(self, beginWord, endWord, wordlist):
        result = []
        def dfs(stack, words):
            if self.is_str_diff_one(stack[-1], endWord):
                result.append(stack + [endWord])
                return

            for idx, word in enumerate(words):
                #print idx, word
                if word in stack: continue
                #if result and len(stack) > len(min(result, key=len)): return 
                if self.is_str_diff_one(stack[-1], word):
                    #print word
                    new_list = words[0:idx] + words[idx+1:]
                    dfs(stack + [word], new_list)

        dfs([beginWord], wordlist)
        if not result: return []
        min_len = len(min(result, key=len))
        res = []

        for r in result:
            if len(r) == min_len:
                res.append(r)
        return res

    def is_str_diff_one(self, s1, s2):
        cnt = 0
        for i in xrange(len(s1)):
            if cnt >= 2: return False
            if s1[i] != s2[i]: cnt += 1

        return False if cnt >= 2 or cnt == 0 else True
    











sol = Solution()
beginWord = "cat" #"qa"
endWord = "fin" #"sq"
wordlist = ["ion","rev","che","ind","lie","wis","oct","ham","jag","ray","nun","ref","wig","jul","ken","mit","eel","paw","per","ola","pat","old","maj","ell","irk","ivy","beg","fan","rap","sun","yak","sat","fit","tom","fin","bug","can","hes","col","pep","tug","ump","arc","fee","lee","ohs","eli","nay","raw","lot","mat","egg","cat","pol","fat","joe","pis","dot","jaw","hat","roe","ada","mac"]

#["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]
print sol.findLadders(beginWord, endWord, wordlist)

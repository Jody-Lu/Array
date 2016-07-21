class Solution(object):
    def findLadders(self, beginWord, endWord, wordlist):
        wordlist = set(wordlist)
        front, back = set([beginWord]), set([endWord])
        wordlist.discard(beginWord)
        res = []

        while front:
            tmp_set = set()
            set_sum = set()
            for word in front:
                for index in xrange(len(beginWord)):
                    for ch in 'abcdefghijklmnopqrstuvwxyz':
                        tmp_set.add(word[:index] + ch + word[index+1:])
                
                tmp_set = tmp_set & wordlist
                
                if not res:
                    res = [[item] for item in tmp_set]
                else:
                    for idx in range(len(res)):
                        if word in res[idx]:
                            res[idx].append(tmp_set)
                            break
                
                set_sum |= tmp_set

            front = wordlist & set_sum

        print res


sol = Solution()
beginWord = "a"
endWord = "c"
wordlist = ["a", "b", "c"]
sol.findLadders(beginWord, endWord, wordlist)
                            








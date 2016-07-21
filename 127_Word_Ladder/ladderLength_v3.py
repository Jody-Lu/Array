class Solution(object):
    def ladderLength(self, beginWord, endWord, wordlist):
        if self.is_str_diff_one(beginWord, endWord): return 2
        stack = [beginWord]
        level = 1
        tmp_stack = []
        while stack:
            tmp = stack.pop()
            if self.is_str_diff_one(tmp, endWord):
                return level + 1


            remain_word = []
            for word in wordlist:
                if self.is_str_diff_one(tmp, word):
                    tmp_stack.insert(0, word)
                else:
                    remain_word.append(word)

            wordlist = remain_word
            if not stack:
                stack, tmp_stack = tmp_stack, stack
                level += 1

        return 0
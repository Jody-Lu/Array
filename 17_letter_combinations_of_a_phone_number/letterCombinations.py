class Solution(object):
    def letterCombinations(self, digits):
        num_dic = {'1':'*', '2': 'abc', '3': 'def',
                    '4': 'ghi', '5': 'jkl', '6': 'mno',
                    '7': 'pqrs', '8':'tuv', '9': 'wxyz',
                    '0': ' '}
        digits = list(digits)
        com_len = len(digits)
        result = []

        def dfs(s, level):
            print s
            if len(s) == com_len: 
                result.append(s)
                return 

            for word in num_dic[digits[level]]:
                dfs(s + word, level + 1)


        dfs('', 0)
        return result

sol = Solution()
sol.letterCombinations('234')

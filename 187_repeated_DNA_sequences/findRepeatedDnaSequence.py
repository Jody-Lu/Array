class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        : type s: str
        : rtype List[str]
        """
        Result = []
        if len(s) < 10:
            return Result

        Str_dic = {}
        idx = 0
        while (idx + 10) <= len(s):
            if Str_dic.has_key(s[idx:idx+10]):
                Str_dic[s[idx:idx+10]] += 1
            else:
                Str_dic[s[idx:idx+10]] = 1            
            idx += 1

        Result = [item[0] for item in Str_dic.items() if item[1] > 1]

        return Result



if __name__ == '__main__':
    sol = Solution()
    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
    s1 = ''
    print sol.findRepeatedDnaSequences(s)


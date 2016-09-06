class Solution(object):
    def longestSubstring(self, s, k):
        count = {c:0 for c in s}
        n = len(s)
        for i in xrange(n):
            if (1 + count[s[i]]) < k:
                if (n - i - 1) < k:
                    break
                else:
                    count[s[i]] += 1
            else:
                count[s[i]] += 1


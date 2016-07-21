class Solution(object):
    def compareVersion(self, version1, version2):
        v1, v2 = (map(int, v.split('.')) for v in (version1, version2))
        print v1
        print v2

sol = Solution()
s1 = '1.0.0.1'
s2 = '1.0.0.0'
sol.compareVersion(s1, s2)

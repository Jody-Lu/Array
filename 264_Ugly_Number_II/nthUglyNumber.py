class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        q = [1]
        p1 = p2 = p3 = 0
        while len(q) < n:
            m1, m2, m3 = q[p1] * 2, q[p2] * 3, q[p3] * 5
            print m1, m2, m3
            mini = min(m1, m2, m3)

            if mini == m1:
                p1 += 1
            if mini == m2:
                p2 += 1
            if mini == m3:
                p3 += 1

            q.append(mini)

        return q[n-1]


sol = Solution()
n = 5
print sol.nthUglyNumber(n)


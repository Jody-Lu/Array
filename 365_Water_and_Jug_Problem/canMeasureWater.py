class Solution(object):
    res = False
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        k = abs(x-y)
        def help(x, y, k, z):
            if z == 0: 
                self.res = True
                return

            for v in [x, y, k]:
                if z - v < 0: continue
                help(x, y, k, z - v)

        help(x, y, k, z)
        return self.res

x = 3
y = 5
z = 4
sol = Solution()
print sol.canMeasureWater(x, y, z)


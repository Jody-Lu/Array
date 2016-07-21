class Solution(object):
    def isPowerOfTwo(self, n):
    	if n == -2147483648: return False
    	c = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    	c = (c & 0x33333333) + ((c >> 2) & 0x33333333);
    	c = (c & 0x0F0F0F0F) + ((c >> 4) & 0x0F0F0F0F);
    	c = (c & 0x00FF00FF) + ((c >> 8) & 0x00FF00FF);
    	c = (c & 0x0000FFFF) + ((c >> 16)& 0x0000FFFF);
        return c == 1

sol = Solution()
print sol.isPowerOfTwo(3)


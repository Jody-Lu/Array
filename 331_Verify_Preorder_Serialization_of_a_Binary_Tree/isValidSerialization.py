class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        p = preorder.split(',')

        slot = 1
        for node in p:
            if slot == 0:
                return False
            if node == '#':
                slot -= 1
            else:
                slot += 1

        return (slot == 0)

sol = Solution()
preorder = "9,#,#,1"
print sol.isValidSerialization(preorder)



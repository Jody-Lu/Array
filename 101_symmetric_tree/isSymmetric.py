
# recursive
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root: return True
        def ifsymmetric(root1, root2):
            if not root1 or not root2:
                return root1 == root2

            if root1.val != root2.val:
                return False
            else:
                return ifsymmetric(root1.left, root2.right) and ifsymmetric(root1.right, root2.left)

        res = ifsymmetric(root.left, root.right)
        return res


# non-recursive

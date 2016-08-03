"""
For a root, 
if (root.val - p.val) * (root.val - q.val) < 0, root must be their common ancestor.
if (root.val - p.val) * (root.val - q.val) > 0, p and q belong to the same subtree. 
if (root.val - p.val) * (root.val - q.val) = 0, root must be the common ancestor.
"""
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        while (root.val - p.val) * (root.val - q.val) > 0:
            root = (root.left, root.right)[p.val > root.val]
        return root

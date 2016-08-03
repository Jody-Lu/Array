class Solution(object):
    def lowestCommonAncestor(self, root, p , q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None

        if root == p or root == q:
            return root

        left_lca = self.lowestCommonAncestor(root.left, p, q)
        right_lca = self.lowestCommonAncestor(root.right, p, q)

        if left_lca and right_lca:
            return root

        return left_lca if left_lca else right_lca

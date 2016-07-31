class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        stack = []
        def dfs(root):
            if not root: return
            if root.left:
                dfs(root.left)
            stack.append(root.val)
            if root.right:
                dfs(root.right)
        dfs(root)
        return stack

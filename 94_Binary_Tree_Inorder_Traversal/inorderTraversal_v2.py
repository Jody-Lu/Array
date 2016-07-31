class Solution(object):
    def inorderTraversal(self, root):
        """
        An iterative version of inorderTraversal.
        """
        res, stack = [], []
        while True:
            while root:
                stack.append(root)
                root = root.left
            if not stack:
                return res
            node = stack.pop()
            res.append(node.val)
            root = node.right


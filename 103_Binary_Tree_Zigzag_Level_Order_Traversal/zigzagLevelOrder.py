class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        current = []
        next = []
        if not root:
            return result
        else:
            current.appen(root)

        while current:
            level = []
            while current:
                node = current[-1]
                current.pop()
                level.append(node.val)
                if node.left:
                    next.insert(0, node.left)
                if node.right:
                    next.insert(0, node.right)
            if len(result) % 2 == 1:
                level.reverse()
            result.append(level)
            current, next = next, current

        return result





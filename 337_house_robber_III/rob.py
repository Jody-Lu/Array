class Solution(object):
    """
    def levelOrder(self,root):
        result = []
        current = []
        next = []

        if not root:
            return result
        else:
            current.insert(0, root)

        while current:
            level = 0
            while current:
                node = current.pop()
                level += node.val
                if node.left: next.insert(0, node.left)
                if node.right: next.insert(0, node.right)
            result.append(level)
            current, next = next, current
        return result
    """
    def rob(self, root):
        """
        :type root: TreeNode
        :rtypr: int
        """
        def dfs_rob(root):
            if not root: return 0,0
            rob_L, no_rob_L = self.dfs_rob(root.left)
            rob_R, no_rob_R = self.dfs_rob(root.right)

            return max(no_rob_L + no_rob_R + root.val, rob_L + rob_R), rob_L + rob_R

        return dfs_rob(root)[0]
    
    

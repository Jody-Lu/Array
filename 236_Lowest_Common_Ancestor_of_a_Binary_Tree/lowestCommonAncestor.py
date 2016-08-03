class Solution(object):
    def findPath(self, root, path, k):
        if not root: 
            return False
        path.append(root)

        if root == k:
            return True
        if ((root.left and self.findPath(root.left, path, k)) or 
                (root.right and self.findPath(root.right, path, k))):
            return True
        path.pop()
        return False

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        path_p = []
        path_q = []

        if (not self.findPath(root, path_p, p)) or (not self.findPath(root, path_q, q)):
                return -1

        i = 0
        while i < len(path_p) and i < len(path_q):
            if path_p[i].val != path_q[i].val:
                break
            i += 1
        return path_p[i - 1]


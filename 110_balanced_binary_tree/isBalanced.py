class Solution(object):
    def post_order(self, root):
        if not root: return
        self.post_order(root.left)
        self.post_order(root.right)
        print root.val

    def isBalanced(self, root):
        def traverse(root):
            if not root: return 
            traverse(root.left)
            traverse(root.right)
            if not root.left and not root.right:
                root.val = 0
            elif not root.left:
                root.val = root.right.val
            elif not root.right:
                root.val = root.left.val
            else:
                root.val = max(root.left.val, root.right.val)

        traverse(root)
        self.post_order(root)
    """
    def isBalanced(self, root):
        def get_height(root):
            left = right = 0
            if not root or (not root.left and not root.right):
                return 0
            if root.left:
                left = 1 + get_height(root.left)
            if root.right:
                right = 1 + get_height(root.right)

            return max(left, right)
        
        if not root or (not root.left and not root.right):
            return True
        left = 1 +  get_height(root.left) if root.left else 0
        right = 1 +  get_height(root.right) if root.right else 0

        if abs(left - right) > 1:
            return False
        elif not self.isBalanced(root.left) or not self.isBalanced(root.right):
            return False
        
        return True
    """


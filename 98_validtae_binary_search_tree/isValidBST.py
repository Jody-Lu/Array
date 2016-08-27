class Solution(object):
    def isValidBST(self, root):
        nodes = []
        def traverse(root):
            if not root: return 
            traverse(root.left)
            nodes.append(root.val)
            traverse(root.right)
        traverse(root)
        for idx in xrange(1, len(nodes)):
            if nodes[idx-1] >= nodes[i]: 
                return False
        else:
            return True
            


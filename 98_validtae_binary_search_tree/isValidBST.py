class Solution(object):
    def isValidBST(self, root):
        nodes = []
        def traverse(root):
            if not root: return 
            traverse(root.left)
            nodes.push_back(root.val)
            traverse(root.right)
        traverse(root)
        for idx in range(len(nodes)):
            if nodes[idx-1] >= nodes[i]: 
                return False
        else:
            return True
            


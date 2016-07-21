class Solution(object):
    def kthSmallest(self, root, k):
        result = []
        def traverse(root):
            if not root or len(result) >= k: return
            traverse(root.left)
            result.append(root -> val)
            traverse(root.right)
        
        traverse(root)
        return result[k-1]

